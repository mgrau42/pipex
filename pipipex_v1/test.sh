echo "starting test" 
echo "ls - l | wc - l"
< files/infile1 ls -l | wc -l > files/outfile1
echo "expected output: "
cat files/outfile1
echo ""
echo "my output: "
./pipex files/infile1 "ls -l" "wc -l" files/outfile2
cat files/outfile2
echo "*****************"
echo "grep a1 | wc - w"
< files/infile1 grep a1 | wc -w > files/outfile1
echo "expected output: "
cat files/outfile1
echo ""
echo "my output: "
./pipex files/infile1 "grep a1" "wc -w" files/outfile2
cat files/outfile2
echo "****************"
echo "notexisting | wc"
< files/infile1 notexisting | wc > files/outfile1
echo "expected output: "
cat files/outfile1
echo "status: "
echo $?
echo ""
echo "my output: "
./pipex files/infile1 "notexisting" "wc" files/outfile2
cat files/outfile2
echo "status: "
echo $?
diff files/outfile1 files/outfile2
echo "****************"
echo "cat | notexisting"
< files/infile1 cat | notexisting > files/outfile1
echo "expected output: "
cat files/outfile1
echo "status: "
echo $?
echo ""
echo "my output: "
./pipex files/infile1 "cat" "notexisting" files/outfile2
cat files/outfile2
echo "status: "
echo $?
diff files/outfile1 files/outfile2
echo "*****************"
echo "assets/deepthought.txt" "cat" "hostname" "outs/test-xx.txt"
< files/infile1 cat | hostname > files/outfile1
cat files/outfile1
echo ""
echo "my output: "
./pipex "files/infile1" "cat" "hostname" "files/outfile2"
cat files/outfile2
echo "*****************"
echo "ls -l| grep u | wc -l"
< files/infile1 ls -l| grep u | wc -l > files/outfile1
cat files/outfile1
echo ""
echo "my output: "
./pipex "files/infile1" "ls -l" "grep u" "wc -l" "files/outfile2"
cat files/outfile2
echo "************"
echo "****************"
echo "cat | notexisting"
< pipex-tester/assets/deepthought.txt cat | notexisting >  pipex-tester/outs/test-x1.txt
echo "expected output: "
cat pipex-tester/outs/test-x1.txt
echo "status: "
echo $?
echo ""
echo "my output: "
./pipex pipex-tester/assets/deepthought.txt "cat" "notexisting" pipex-tester/outs/test-xx.txt
cat pipex-tester/outs/test-xx.txt
echo "status: "
echo $?
diff files/outfile1 files/outfile2
echo "*****************"

echo "Cleaning files"
rm -rf files/outfile1 files/outfile2
touch files/outfile1 files/outfile2
