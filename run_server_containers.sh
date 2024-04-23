tmux new-session -d -s mySession -n myWindow
tmux split-window -hf
tmux send-keys -t mySession:myWindow "sudo docker run -p 80:80 jod.web_client_server:latest" Enter
tmux select-pane -L
tmux send-keys -t mySession:myWindow "sudo docker run -p 1238:1238 jod.game_server:latest" Enter
tmux split-window -hf
tmux select-pane -L
tmux attach -t mySession:myWindow
