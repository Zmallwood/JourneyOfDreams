#!/bin/bash

cd ../bin

tmux new-session -d -s mySession -n myWindow
tmux split-window -hf
tmux send-keys -t mySession:myWindow "./Server" Enter
tmux select-pane -L
tmux send-keys -t mySession:myWindow "python -m http.server" Enter
tmux split-window -hf
tmux select-pane -L
tmux attach -t mySession:myWindow
