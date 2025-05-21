cd %USERPROFILE%\Desktop
mkdir CSC2244 Marks Exam
cd CSC2244
mkdir practical theory "exam papers"
cd practical
echo. > practical.txt
type nul > practical.docx
type nul > practical.pptx

cd ..\theory
echo. > theory.txt
type nul > theory.docx
type nul > theory.pptx

cd ..\"exam papers"
echo. > exam_papers.txt
type nul > exam_papers.docx
type nul > exam_papers.pptx

move %USERPROFILE%\Desktop\"Icae Marks.xlsx" %USERPROFILE%\Desktop\Marks
move %USERPROFILE%\Desktop\"Final Exam Marks.xlsx" %USERPROFILE%\Desktop\Marks

xcopy %USERPROFILE%\Desktop\Marks %USERPROFILE%\Desktop\Exam\Marks /E /I
attrib +h %USERPROFILE%\Desktop\Exam
