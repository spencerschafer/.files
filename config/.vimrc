set number
set relativenumber
set backspace=indent,eol,start
set ruler
set tabstop=4
set shiftwidth=4
set cc=80
set mouse=a
syntax on
filetype plugin indent on
colorscheme monokai

"type :hi to see colours
"ctermfg sets number colour
"ctermbg sets background colour

"Highlight line number -- blue
hi CursorLineNr ctermfg=81

"Highlight block instead of number -- blue 
"hi CursorLineNr ctermfg=234 ctermbg=81 

"Use this on linux 
"Eliminates highlighting of both brackets
"let loaded_matchparen = 1
