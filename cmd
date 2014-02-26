git filter-branch --prune-empty -d /dev/shm/scratch \
  --index-filter "git rm --cached -f --ignore-unmatch java/aida-2.0.4-jar-with-dependencies.jar" \
  --tag-name-filter cat -- --all

