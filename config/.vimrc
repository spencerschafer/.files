set number
set relativenumber
set backspace=indent,eol,start
set ruler
set tabstop=4
set shiftwidth=4
set cc=80
syntax on
filetype plugin indent on
colorscheme monokai

"type :hi in vim to bring up a list of colours applied to line numbers
"search for the relevant values and replace in the line below to modify the
"colour of the relative number

"Highlight block instead of number
"hi CursorLineNr term=reverse ctermfg=234 ctermbg=81 guifg=#272822 guibg=#66d9ef

"Highlight number line
hi CursorLineNr ctermfg=81 guifg=#66d9ef

"Use this on linux to eliminate highlighting of both brackets
"let loaded_matchparen = 1
