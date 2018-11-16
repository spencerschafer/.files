# Shortcuts
#export PS1="\[\e[01;32m\]->\[\e[0m\]" #bash
export PS1=$'\e[0;32m->\e[0m' #zsh
export f="$HOME/.files/"
export rmb="$HOME/.rmb/"
export p="$HOME/.projects/"
export zp="$HOME/.zprofile"
#
#CocoaPods
export GEM_HOME=$HOME/.gem
#export PATH=$GEM_HOME/bin:$PATH
export PATH=/goinfre/sschafer/.gem/ruby/2.3.0/bin:$PATH

# Compilation
alias compg="gcc -Wall -Werror -Wextra"
alias compc="clang++ -Wall -Werror -Wextra"
alias compdb="comp -ggdb"
alias val="valgrind --leak-check=full"
alias norm="norminette"
alias normall="find . -name \"*.[c|h]\" -exec norminette {} \;"
alias cc="gcc -Wall -Werror -Wextra -Isrcs/mlx -Lsrcs/mlx -lmlx \\ 
			-framework OpenGL -framework AppKit \\
			-I libft/includes libft/libft.a"
alias cc="gcc -Wall -Werror -Wextra -Isrcs/mlx -Lsrcs/mlx -lmlx -framework\\
			OpenGL -framework AppKit -I libft/includes libft/libft.a  *.c"
alias delk="k delete clusterrolebindings service-reader-default && \\
			k delete clusterrolebindings service-reader-k8s"
		
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
alias startmp="kubectl port-forward -n marketplace-dev \"\$(kubectl get -n marketplace-dev pod --selector=app=zero-coupon-deposit,component=database -o jsonpath='{.items..metadata.name}')\" 5433"
alias startnr"kubectl port-forward -n messaging \"\$(kubectl get -n messaging pod --selector=app=node-red-app -o jsonpath='{.items..metadata.name}')\" 1880"
alias startds="kubectl port-forward -n messaging \"\$(kubectl get -n messaging pod --selector=app=data-science-db,component=database -o jsonpath='{.items..metadata.name}')\" 5432"
#brew
alias brewclean="brew update && brew upgrade && brew cleanup &&\\
				 brew cask upgrade && brew cask cleanup && brew doctor"

# Terminal
alias ls="ls -FG"
alias lsa="ls -a"
alias lsl="ls -1"
alias lsla="ls -1a"
alias srcz="source ~/.zprofile"
#printing the 4th line of stdouti: ls -la | sed -n 4p

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
