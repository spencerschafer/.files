# Shortcuts
export PS1="%F{green}%~%f>"
export g="$HOME/.github/"
export fdf="$HOME/.github/FdF"
alias fc='bash ~/.42FileChecker/42FileChecker.sh'

# Compilation
alias comp="gcc -Wall -Werror -Wextra"
alias compdb="comp -ggdb"
alias val="valgrind --leak-check=full"
alias norm="norminette"
alias normall="find . -name \"*.[c|h]\" -exec norminette {} \;"
alias cc="comp -Ilibft/includes libft/libft.a \\
		-Isources/mlx -Lsources/mlx -lmlx \\
		-framework OpenGL -framework AppKit main.c"
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
alias gcl="git clone"
alias gp="git push"

# Loads Homebrew version until Sierra used - Note this is a temporary work around
#export PATH=/usr/local/bin:$PATH

# Load Homebrew Fix script
#source $HOME/.brew_fix.zsh
