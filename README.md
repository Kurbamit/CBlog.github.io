# CBlog.github.io

### How to use

This program converts a plain text file with tagged lines into an ready-to-use html file.

Currently, a line (text followed by EOF or a newline character) may only have tag, which must be right at it's beginning.

To convert a file to html, run the program compiled from generator.c in the command line supplying the input filename and output filename as arguments, like this: 

`generator input.txt output.html`

Currently, generated html files have a hardcoded requirement for a CSS file named style.css in the same directory.

-------

### Tags

All tags follow the format of a # (hashtag) symbol followed **only** by plaintext characters, with no whitespace.

Currently supported tags:

| Tag       | Equivalent to |
|-----------|---------------|
| #title    | `<h1>`        |
| #subtitle | `<h2>`        |
| #section  | `<h3>`        |

-------

### Example

    #title Title
    
    #section Section
    text text text
    
    #subtitle Subtitle
    more text more text

Becomes

    <html>
    	<head>
    		<meta charset="utf-8">
    		<meta name="viewport" content="width=device-width, initial-scale=1">
    		<title>TESTOR</title>
    		<link rel="stylesheet" href="style.css">
    	</head>
    	<body>
    		<h1>Title</h1>
    		<h3>Section</h3>
    		<p>text text text</p>
    		<h2>Subtitle</h2>
    		<p>more text more text</p>
    	</body>
    </html>
