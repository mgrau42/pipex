

printf "

================================================================================

██████╗ ██╗██████╗ ███████╗██╗  ██╗    ███╗   ███╗██████╗██████╗  ██████╗██╗  ██╗ 
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝    ████╗ ████║██╔═██║██╔══██╗ ██╔═██║██║  ██║ 
██████╔╝██║██████╔╝█████╗   ╚███╔╝     ██╔████╔██║██████║██████╔╝ ██████║██║  ██║ 
██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗     ██║╚██╔╝██║    ██║██╔═══██╗██╔═██║██║  ██║ 
██║     ██║██║     ███████╗██╔╝ ██╗    ██║ ╚═╝ ██║██████║██║   ██╗██║ ██║███████║
╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚═════╝╚═╝   ╚═╝╚═╝ ╚═╝╚══════╝ 

================================================================================
"
RED='\033[1;31m'
GREEN='\033[32m'
YELLOW='\033[33m'
BLUE='\033[34m'
MAGENTA='\033[35m'
CYAN='\033[36m'
RESET='\033[0m'
WHITE='\033[1;37m'
GRAY='\033[1;32m'

printf "${GREEN} Starting Test ${RESET} \n\n" 
printf "${YELLOW}*****************${RESET}\n"

#test 1
printf "${GREEN}TEST 01  ${YELLOW}ls - l | wc - l ${RESET}\n"
printf "${WHITE}expected output: ${RESET}\n"
< files/infile1 ls -l | wc -l > files/outfile1
cat -e files/outfile1
printf "${WHITE}status: ${RESET}\n"
< files/infile1 ls -l | wc -l > files/outfile1
printf $?
printf "\n"
printf "${WHITE}my output: ${RESET}\n"
./pipex files/infile1 "ls -l" "wc -l" files/outfile2
cat -e files/outfile2
printf "${WHITE}status: ${RESET}\n"
./pipex files/infile1 "ls -l" "wc -l" files/outfile2
printf $?
printf "\n"
printf "${YELLOW}*****************${RESET}\n\n"

#test 2
printf "${YELLOW}*****************${RESET}\n"
printf "${GREEN}TEST 02  ${YELLOW}grep a1 | wc - w ${RESET}\n"
printf "${WHITE}expected output: ${RESET}\n"
< files/infile1 grep a1 | wc -w > files/outfile1
cat files/outfile1
printf "${WHITE}status: ${RESET}\n"
< files/infile1 grep a1 | wc -w > files/outfile1
printf $?
printf "\n"
printf "${WHITE}my output: ${RESET}\n"
./pipex files/infile1 "grep a1" "wc -w" files/outfile2
cat files/outfile2
printf "${WHITE}status: ${RESET}\n"
./pipex files/infile1 "grep a1" "wc -w" files/outfile2
printf $?
printf "\n"
printf "${YELLOW}*****************${RESET}\n\n"

#test 3
printf "${YELLOW}*****************${RESET}\n"
printf "${GREEN}TEST 03  ${YELLOW}notexisting | wc ${RESET}\n"
printf "${WHITE}expected output: ${RESET}\n"
< files/infile1 notexisting | wc > files/outfile1
cat files/outfile1
printf "${WHITE}status: ${RESET}\n"
< files/infile1 notexisting | wc > files/outfile1
printf $?
printf ""
printf "\n${WHITE}my output: ${RESET}\n"
./pipex files/infile1 "notexisting" "wc" files/outfile2
cat files/outfile2
printf "\n${WHITE}status: ${RESET}\n"
./pipex files/infile1 "notexisting" "wc" files/outfile2
printf $?
diff files/outfile1 files/outfile2
printf "\n${YELLOW}*****************${RESET}\n\n"

#test 4
printf "${YELLOW}*****************${RESET}\n"
printf "${GREEN}TEST 04  ${YELLOW}cat | notexisting ${RESET}\n"
printf "${WHITE}expected output: ${RESET}\n"
< files/infile1 cat | notexisting > files/outfile1
cat files/outfile1
printf "${WHITE}status: ${RESET}\n"
< files/infile1 cat | notexisting > files/outfile1
printf $?
printf ""
printf "\n${WHITE}my output: ${RESET}\n"
./pipex files/infile1 "cat" "notexisting" files/outfile2
cat files/outfile2
printf "${WHITE}status: ${RESET}\n"
./pipex files/infile1 "cat" "notexisting" files/outfile2
printf $?
diff files/outfile1 files/outfile2
printf "\n${YELLOW}*****************${RESET}\n\n"

#test 5
printf "${YELLOW}*****************${RESET}\n"
printf "${GREEN}TEST 05  ${YELLOW}cat | hostname ${RESET}\n"
< files/infile1 cat | hostname > files/outfile1
cat files/outfile1
printf "${WHITE}status: ${RESET}\n"
< files/infile1 cat | hostname > files/outfile1
printf $?
printf "\n"
printf "${WHITE}my output: ${RESET}\n"
./pipex "files/infile1" "cat" "hostname" "files/outfile2"
cat files/outfile2
printf "${WHITE}status: ${RESET}\n"
./pipex "files/infile1" "cat" "hostname" "files/outfile2"
printf $?
printf "\n"
printf "${YELLOW}*****************${RESET}\n\n"

#test 6
printf "${YELLOW}*****************${RESET}\n"
printf "${GREEN}TEST 06  ${YELLOW} noinfile ls - l | wc - l ${RESET}\n"
printf "${WHITE}expected output: ${RESET}\n"
< noinfile1 ls -l | wc -l > files/outfile1
cat -e files/outfile1
printf "${WHITE}status: ${RESET}\n"
< nofile1 ls -l | wc -l > files/outfile1
printf $?
printf "\n"
printf "${WHITE}my output: ${RESET}\n"
./pipex nofile1 "ls -l" "wc -l" files/outfile2
cat -e files/outfile2
printf "${WHITE}status: ${RESET}\n"
./pipex nofile1 "ls -l" "wc -l" files/outfile2
printf $?
printf "\n"
printf "${YELLOW}*****************${RESET}\n\n"

#test 7
printf "${YELLOW}*****************${RESET}\n"
printf "${GREEN}TEST 07  ${YELLOW} nooutfile ls - l | wc - l ${RESET}\n"
printf "${WHITE}expected output: ${RESET}\n"
< files/infile1 ls -l | wc -l > nooutfile1
cat -e nooutfile1
rm -rf nooutfile1
printf "${WHITE}status: ${RESET}\n"
< files/infile1 ls -l | wc -l > nooutfile1
printf $?
printf "\n"
rm -rf nooutfile1
printf "${WHITE}my output: ${RESET}\n"
./pipex files/infile1 "ls -l" "wc -l" nooutfile2
cat -e nooutfile2
rm -rf nooutfile2
printf "${WHITE}status: ${RESET}\n"
./pipex files/infile1 "ls -l" "wc -l" nooutfile2
printf $?
printf "\n"
rm -rf nooutfile2
printf "${YELLOW}*****************${RESET}\n\n"

#test 8
printf "${YELLOW}*****************${RESET}\n"
printf "${GREEN}TEST 08  ${YELLOW}1 arg ${RESET}\n"
printf "${WHITE}my output: ${RESET}\n"
./pipex files/infile1 "wc -l" files/outfile2
cat -e files/outfile2
printf "${WHITE}status: ${RESET}\n"
./pipex files/infile1 "wc -l" files/outfile2
printf $?
printf "\n"
printf "${YELLOW}*****************${RESET}\n\n"


#test bonus 1
printf "${YELLOW}*****************${RESET}\n"
printf "${GREEN}BONUS TEST 01  ${YELLOW}ls -l| grep u | wc -l${RESET}\n"
< files/infile1 ls -l| grep u | wc -l > files/outfile1
cat files/outfile1
printf ""
printf "${WHITE}status: ${RESET}\n"
< files/infile1 ls -l| grep u | wc -l > files/outfile1
printf $?
printf "\n"
printf "${WHITE}my output: ${RESET}\n"
./pipex "files/infile1" "ls -l" "grep u" "wc -l" "files/outfile2"
cat files/outfile2
printf "${WHITE}status: ${RESET}\n"
./pipex "files/infile1" "ls -l" "grep u" "wc -l" "files/outfile2"
printf $?
printf "\n"
printf "${YELLOW}*****************${RESET}\n\n"

printf "Cleaning files"
rm -rf files/outfile1 files/outfile2
touch files/outfile1 files/outfile2
