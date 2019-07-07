function measure()
{
    echo -n "Non recursive: "
    /usr/bin/time --format='%e' $1 n
    echo -n "Recursive: "
    /usr/bin/time --format='%e' $1 r
    echo
}

echo "Directories: $(find data -type d | wc -l)"
echo "Files: $(find data -type f | wc -l)"
echo

echo "glob"
measure "./glob_list.py"

echo "Pathlib.glob"
measure "./pathlib_list.py"

echo "fastglob.glob"
measure "./fastglob_list.py"
