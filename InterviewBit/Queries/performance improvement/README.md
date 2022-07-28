You are given a table having the marks of one student in every test (Tests are held every day) . 
You have to output the tests in which the student has improved his performance. 
For a student to improve his performance he has to score more than the previous test. 

Table : Tests <br />
![image](https://user-images.githubusercontent.com/92727668/181509334-868e0fc4-8b86-4406-86c0-68ff9ace3974.png)


NOTE : The output should contain one column by the name ‘TestId’ .

Example :

![image](https://user-images.githubusercontent.com/92727668/181509389-17c00211-3892-493d-af52-34bba120bc19.png)

-- Query Sol -- <br />
**SELECT Tests.TestId FROM Tests JOIN Tests as t ON t.TestId = Tests.TestId-1 WHERE Tests.Marks>t.Marks**
