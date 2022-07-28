Given a table FIREFIGHTERS, query the average of all the people saved by the Firefighters whose CountryCode is PM.

The description of the table FIREFIGHTERS is as follows:

![image](https://user-images.githubusercontent.com/92727668/181507118-331bae85-6660-474a-98f2-47c2da6f85d8.png)

NOTE : The output should contain only 1 column ‘AVG(PeopleSaved)’ .

Example : 

![image](https://user-images.githubusercontent.com/92727668/181507150-ae139bbf-5a98-4aa8-bf56-ae5e895db34f.png)

-- Query sol -- <br />
**SELECT AVG(PeopleSaved) FROM FIREFIGHTERS WHERE CountryCode="PM"**
