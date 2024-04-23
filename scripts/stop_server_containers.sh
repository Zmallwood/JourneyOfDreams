docker stop $(docker ps -a -q) &&
tmux kill-server
