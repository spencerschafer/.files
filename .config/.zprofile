# Shortcuts
export PS1="%F{green}%~%f>"
export g="$HOME/.github/"
export e="$HOME/.github/expert-system/"

# Compilation
alias comp="gcc -Wall -Werror -Wextra"
alias compdb="comp -ggdb"
alias val="valgrind --leak-check=full"
alias norm="norminette"
alias normall="find . -name \"*.[c|h]\" -exec norminette {} \;"

# Terminal
alias ls="ls -FG"
alias lsa="ls -a"
alias lsl="ls -1"
alias lsla="ls -1a"
alias rez="source ~/.zprofile"

# Git
alias ga="git add"
alias gs="git status"
alias gsc="git status --column"
alias gc="git commit -m"
alias gp="git push"

# Loads Homebrew file versions - For school use.
export PATH=/usr/local/bin:$PATH

# Load Homebrew Fix script
source $HOME/.brew_fix.zsh
