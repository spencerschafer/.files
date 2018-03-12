# Shortcuts
export PS1="%F{green}%~%f>"
export d="$HOME/.dotfiles/"
export f="$HOME/.foundery/"
export p="$HOME/.projects/"
export fdf="$HOME/.github/FdF"

# Compilation
alias comp="gcc -Wall -Werror -Wextra"
alias compdb="comp -ggdb"
alias val="valgrind --leak-check=full"
alias norm="norminette"
alias normall="find . -name \"*.[c|h]\" -exec norminette {} \;"
alias cc="gcc -Wall -Werror -Wextra -Isrcs/mlx -Lsrcs/mlx -lmlx \\ 
			-framework OpenGL -framework AppKit \\
			-I libft/includes libft/libft.a"
alias cc="gcc -Wall -Werror -Wextra -Isrcs/mlx -Lsrcs/mlx -lmlx -framework\\
			OpenGL -framework AppKit -I libft/includes libft/libft.a  *.c"
		
# Docker
alias dockerpsi="docker ps -a; echo ""; docker images -a"
alias dockerclean="docker stop \$(docker ps -aq); docker system prune -a"

# Kubernetes
alias k="kubectl "
alias km="kubectl -n messaging"
alias startmk="minikube start --vm-driver hyperkit && eval \$(minikube docker-env)"
alias stopmk="minikube stop"
alias evalmini="eval \$(minikube docker-env)"

#brew
alias brewclean="brew update && brew upgrade && brew cleanup &&\\
					brew cask upgrade && brew cask cleanup && brew doctor"

# Terminal
alias ls="ls -FG"
alias lsa="ls -a"
alias lsl="ls -1"
alias lsla="ls -1a"
alias resz="source ~/.zprofile"

# Git
alias ga="git add"
alias gs="git status"
alias gsc="git status --column"
alias gc="git commit -m"
alias gcl="git clone"
alias gp="git push"

#ENV
alias settc=". ~/.dotfiles/.config/set-tc.sh"
alias unsettc=". ~/.dotfiles/.config/unset-tc.sh"

# Load Homebrew Fix script
#source $HOME/.brew_fix.zsh
