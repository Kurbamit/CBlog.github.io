# CBlog.github.io

This program converts a plain text file with tagged lines into an ready-to-use html file.

Currently, a line (text followed by EOF or a newline character) may only have tag, which must be right at it's beginning.

To convert a file to html, run the program compiled from generator.c in the command line supplying the input filename and output filename as arguments, like this: 

`generator input.txt output.html`

Currently, generated html files have a hardcoded requirement for a CSS file named style.css in the same directory.

# Tags

All tags follow the format of a # (hashtag) symbol followed **only** by plaintext characters, with no whitespace.

Currently supported tags:

| Tag       | Equivalent to |
|-----------|---------------|
| #title    | `<h1>`        |
| #subtitle | `<h2>`        |
| #section  | `<h3>`        |
