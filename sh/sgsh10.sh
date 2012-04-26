#sg
trap 'echo GOT KILL" ' KILL
trap  'echo "GOT TERM" ' TERM
while true
do
sleep 300;
done

