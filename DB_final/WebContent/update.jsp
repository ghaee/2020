<%@ page contentType="text/html; charset=EUC-KR" %>
<%@ page import="java.sql.*" %>
<html> <head><title>������û ����� ���� ����</title></head>
<body> <%@ include file="top.jsp" %>
<%
if (session_id==null) response.sendRedirect("login.jsp");

String dbdriver = "oracle.jdbc.driver.OracleDriver";
String dburl = "jdbc:oracle:thin:@localhost:1521:orcl";
String user = "db1510188";
String passwd = "test";

try{
	Class.forName(dbdriver);
	Connection myConn;
	myConn=DriverManager.getConnection(dburl, user, passwd);
	
	Statement stmt;
	String mySQL =  "select * from student where s_id='" + session_id + "'" ;
	
	stmt = myConn.createStatement();
	ResultSet result = stmt.executeQuery(mySQL);
	if(result.next()){
		// <tr> <td align= "center"><%= session_id �� �湮�� ȯ���մϴ� .</td> </tr>
	}else{
		
	}
	
}catch(Exception e){
	 out.println("DB ���� ����");
}%>
<!-- <form method="post" action="update_verify.jsp"> 
��
</form></body></html> -->

