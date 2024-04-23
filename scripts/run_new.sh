session="mySession"

# Check if the session exists, discarding output
# We can check $? for the exit status (zero for success, non-zero for failure)
tmux has-session -t $session 2>/dev/null

if [ $? == 0 ]; then
  tmux kill-server
fi

docker stop $(docker ps -a -q) &&
./build.sh &&
sudo ./run_server_containers.sh
