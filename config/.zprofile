export PS1="%F{green}%~%f>"
export b="$HOME/.bitbucket/"
export c="$HOME/.bitbucket/temp/corewar"
alias comp="gcc -Wall -Werror -Wextra"
alias val="valgrind --leak-check=full"
alias norm="norminette"
alias normall="find . -name \"*.[c|h]\" -exec norminette {} \;"
alias ls="ls -FG"
alias ga="git add"
alias gs="git status"
alias gc="git commit -m"
alias gp="git push"

# Load Homebrew Fix script
source $HOME/.brew_fix.zsh
