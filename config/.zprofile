export PS1="%F{green}%~%f>"
export b="$HOME/.bitbucket/"
export c="$HOME/.bitbucket/temp/corewar"
alias comp="gcc -Wall -Werror -Wextra"
alias compdb="comp -ggdb"
alias val="valgrind --leak-check=full"
alias norm="norminette"
alias normall="find . -name \"*.[c|h]\" -exec norminette {} \;"
alias ls="ls -FG"
alias lsa="ls -a"
alias lsl="ls -1"
alias lsla="ls -1a"
alias ga="git add"
alias gs="git status"
alias gsc="git status --column"
alias gc="git commit -m"
alias gp="git push"

# Loads Homebrew version until Sierra used - Note this is a temporary work around
#export PATH=/usr/local/bin:$PATH

# Load Homebrew Fix script
#source $HOME/.brew_fix.zsh
