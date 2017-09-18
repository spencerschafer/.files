set number
set relativenumber
set ruler
set tabstop=4
set shiftwidth=4
set cc=80
syntax on
let loaded_matchparen = 1
filetype plugin indent on
colorscheme monokai

"type :hi in vim to bring up a list of colours applied to line numbers
"search for the relevant values and replace in the line below to modify the
"colour of the relative number
hi CursorLineNr term=reverse ctermfg=234 ctermbg=81 guifg=#272822 guibg=#66d9ef
