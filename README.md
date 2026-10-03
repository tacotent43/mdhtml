# mdhtml
Markdown to HTML converter written in C++20.

## Building
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
./mdhtml
```

## Project Structure
```
mdhtml
├── ast/                              // abstract syntax tree
│   ├── include/ast/
│   │   ├── Node.h                    // base class for all nodes
│   │   ├── BlockNode/
│   │   │   ├── _BlockNode.h          // inherited from abstract class Node for block nodes
│   │   │   ├── Document.h/cpp
│   │   │   ├── Heading.h/cpp
│   │   │   ├── CodeBlock.h/cpp
│   │   │   ├── List.h/cpp
│   │   │   ├── ListItem.h/cpp
│   │   │   └── Paragraph.h/cpp
│   │   └── InlineNode/              // inherited from abstract class Node for inline nodes
│   │       ├── _InlineNode.h
│   │       ├── Bold.h/cpp
│   │       ├── Italic.h/cpp
│   │       ├── InlineCode.h/cpp
│   │       ├── Link.h/cpp
│   │       └── Text.h/cpp
│   └── src/
├── lexer/                            // lexer
│   ├── include/lexer/
│   │   ├── ClassifiedChar.h          // classified character
│   │   ├── Position.h                // position in source code
│   │   ├── SourceCursor.h            // cursor in source code
│   │   ├── SpecialCharKind.h         // char kinds for tokens classification
│   │   ├── Token.h                   // token itself
│   │   ├── TokenType.h               // enum of types of tokens and their string representations (for debugging)
│   │   └── Lexer.h                   // main lexer class
│   └── src/
├── utils/                            // additional utilities
│   ├── include/utils/
│   │   ├── CharCheckers.h
│   │   ├── EscapeHtml.h
│   │   ├── Exceptions.h              // custom exceptions
│   │   ├── FormatString.h            // std::vformat wrapper for custom and pretty format strings
│   │   └── ShortenString.h           // small string shortener for quick debug AST representations
│   └── src/
├── CMakeLists.txt
├── LICENSE
├── README.md
├── hello.md
└── main.cpp
```

## What's Implemented
- **Lexer** - Markdown tokenization, including code fence detection (` ``` `)
- **Utilities** - HTML escaping, string formatting, exception helpers
- **AST** - node tree (Document, Heading, CodeBlock, List, ListItem, Paragraph, Bold, Italic, InlineCode, Link, Text) + additional things later
- **HTML generation** - basic nodes can "representate" themselves via `toHtml()`

## TODO
- Parse tokens into IR (currently only tokenization is working)
- Full support for ordered and unordered lists
- Headings, inline formatting, and link parsing, quotes, quote blocks etc. 
- Math formulas (`$$...$$`) (of course)
- Blockquotes (`> ...`)
- etc.
