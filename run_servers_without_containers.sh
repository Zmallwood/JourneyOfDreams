#!/bin/bash

cd ../bin

tmux new-session -d -s mySession -n myWindow
tmux split-window -hf
tmux send-keys -t mySession:myWindow "../bin_server/Server" Enter
tmux select-pane -L
tmux send-keys -t mySession:myWindow "cd ../bin_web_client && sudo python -m http.server 80" Enter
tmux split-window -hf
tmux select-pane -L
tmux attach -t mySession:myWindow
