#!/bin/bash

NC='\033[0m'
GR='\033[0;32m'
RED='\033[0;31m'

unset KUBECONFIG
if [[ -z $(env | grep  KUBECONFIG) ]]; then
	echo -e "[ ${GR}ENV REMOVED: KUBECONFIG${NC} ]"
else
	echo -e "[ ${RED}ENV ERROR: KUBECONFIG${NC} ]"
fi

if [[ $(kubectl config current-context) = 'minikube'  ]]; then
	echo -e "[ ${GR}CONTEXT SET: minikube${NC} ]"
else
	echo -e "[ ${RED}CONTEXT ERROR: default${NC} ]"
fi
