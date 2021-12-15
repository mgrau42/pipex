echo "starting test" 
echo "ls - l | wc - l"
< infile1 ls -l | wc -l > outfile1
echo "expected output: "
cat outfile1
echo ""
echo "my output: "
./pipex infile1 "ls -l" "wc -l" outfile2
cat outfile2
echo ""
echo "grep a1 | wc - w"
< infile1 grep a1 | wc -w > outfile1
echo "expected output: "
cat outfile1
echo ""
echo "my output: "
./pipex infile1 "notexisting" "wc" outfile2
cat outfile2
diff outfile1 outfile2
echo ""
echo "assets/deepthought.txt" "cat" "hostname" "outs/test-xx.txt"
< infile1 cat | hostname > outfile1
cat outfile1
./pipex "infile1" "cat" "hostname" "outfile2"
cat outfile2

echo "Cleaning files"
rm -rf outfile1 outfile2
touch outfile1 outfile2
