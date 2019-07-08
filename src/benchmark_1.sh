function profile_script()
{
    echo -n "Non recursive: "
    /usr/bin/time --format='%e' python $1 n
    echo -n "Recursive: "
    /usr/bin/time --format='%e' python $1 r
    echo
}

echo "Directories: $(find data -type d | wc -l)"
echo "Files: $(find data -type f | wc -l)"
echo

echo "glob"
profile_script "./glob_list.py"

echo "Pathlib.glob"
profile_script "./pathlib_list.py"

echo "fastglob.glob"
profile_script "./fastglob_list.py"
