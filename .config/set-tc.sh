#!/bin/bash

echo "[Setting kubectl environment]"
export KUBECONFIG="/Users/Spencer/.kube/config.azure-1"
kubectl config use-context foundery-kubernetes-2
echo "[kubectl environment set to teamcity]"
