#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 9

enum Tag {
	T_TITLE,
	T_SUBTITLE,
	T_SECTION,
	T_NOTAG
};

char* getHtmlTag(enum Tag tag) {
	static char* htmlTags[] = {
		"h1",
		"h2",
		"h3",
		"p"
	};

	if(tag == T_TITLE) return htmlTags[0];
	if(tag == T_SUBTITLE) return htmlTags[1];
	if(tag == T_SECTION) return htmlTags[2];
	if(tag == T_NOTAG) return htmlTags[3];
	return NULL;
}

enum Tag matchTagName(char* tagName) {
	if(strcmp(tagName, "title") == 0) return T_TITLE;
	if(strcmp(tagName, "subtitle") == 0) return T_SUBTITLE;
	if(strcmp(tagName, "section") == 0) return T_SECTION;
	return T_NOTAG;
}

enum Tag readTag(FILE* textInput) {
	char tagName[9] = {};
	int i = 0;
	char c = fgetc(textInput);

	while(c != EOF && c != '\n' && c != ' '){
		if(i < MAX_TAG_NAME_LENGTH){
			tagName[i] = c;
            ++i;
		}
		c = fgetc(textInput);
	}
	tagName[i] = '\0';
	return matchTagName(tagName);
}

int main(int argc, char *argv[]) {
    FILE *textInput = fopen(argv[1], "r");

    if (textInput == NULL) {
        fprintf(stderr, "Failed to open file for reading\n");
        perror("Error");
        return 0;
    }

    FILE *htmlOutput = fopen(argv[2], "w");

    if (htmlOutput == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        perror("Error");
        return 0;
    }

    char c = fgetc(textInput);

    fprintf(htmlOutput, "<html>\n\t<head>\n\t\t<meta charset=\"utf-8\">\n\t\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n\t\t<title>TESTOR</title>\n\t\t<link rel=\"stylesheet\" href=\"style.css\">\n\t</head>\n\t<body>\n");

    while(c != EOF){
        if (c != '\n') {
            enum Tag tag = T_NOTAG;
            if (c == '#') {
                tag = readTag(textInput);
                c = fgetc(textInput);
            }
            char* htmlTag = getHtmlTag(tag);

            fprintf(htmlOutput, "\t\t<%s>", htmlTag);

            while(c != EOF && c != '\n'){
                fputc(c, htmlOutput);
                c = fgetc(textInput);
            }

            fprintf(htmlOutput, "</%s>\n", htmlTag);
        }
        else {
            c = fgetc(textInput);
        }
    }

    fprintf(htmlOutput, "\t</body>\n</html>");
}
