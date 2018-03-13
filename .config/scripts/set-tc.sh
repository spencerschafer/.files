#!/bin/bash

NC='\033[0m'
GR='\033[0;32m'
RED='\033[0;31m'

export KUBECONFIG="/Users/Spencer/.kube/config.azure-1"
kubectl config use-context foundery-kubernetes-2 &> /dev/null

if [[ $(env | grep  KUBECONFIG) = 'KUBECONFIG=/Users/Spencer/.kube/config.azure-1'  ]]; then
	echo -e "[ ${GR}ENV SET: KUBECONFIG${NC} ]"
else
	echo -e "[ ${RED}ENV ERROR: KUBECONFIG${NC} ]"
fi

if [[ $(kubectl config current-context) = 'foundery-kubernetes-2'  ]]; then
	echo -e "[ ${GR}CONTEXT SET: foundery-kubernetes-2${NC} ]"
else
	echo -e "[ ${RED}CONTEXT ERROR: foundery-kubernetes-2${NC} ]"
fi
