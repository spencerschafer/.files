# Shortcuts
export PS1="%F{cyan}%~%f>"
export f="$HOME/.files/"
export rmb="$HOME/.rmb/"
export p="$HOME/.projects/"

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
alias setmini="eval \$(minikube docker-env)"
alias unsetmini="eval \$(minikube docker-env -u)"
alias kcontext="k config current-context"
alias startws="kubectl port-forward -n weave \"\$(kubectl get -n weave pod --selector=weave-scope-component=app -o jsonpath='{.items..metadata.name}')\" 4040"

#brew
alias brewclean="brew update && brew upgrade && brew cleanup &&\\
					brew cask upgrade && brew cask cleanup && brew doctor"

# Terminal
alias ls="ls -FG"
alias lsa="ls -a"
alias lsl="ls -1"
alias lsla="ls -1a"
alias srcz="source ~/.zprofile"

# Git
alias ga="git add"
alias gs="git status"
alias gsc="git status --column"
alias gc="git commit -m"
alias gcl="git clone"
alias gp="git push"

#ENV
alias settc=". ~/.files/.config/scripts/set-tc.sh"
alias unsettc=". ~/.files/.config/scripts/unset-tc.sh"
export NVM_DIR="$HOME/.nvm"
. "/usr/local/opt/nvm/nvm.sh"

# Load Homebrew Fix script
#source $HOME/.brew_fix.zsh
