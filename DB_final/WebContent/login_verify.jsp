<%@ page language= "java" contentType ="text/html; charset=UTF-8" pageEncoding ="UTF-8"%> 
<%@page import= "java.sql.*"%>
<% 
String userID=request.getParameter("userID"); 
String userPassword=request.getParameter("userPassword"); 
//test -> 1200032    bzxa23


String dbdriver = "oracle.jdbc.driver.OracleDriver";
String dburl = "jdbc:oracle:thin:@localhost:1521:orcl";
String user = "db1510188";
String passwd = "test"; 
try{
	Class.forName(dbdriver);
	Connection myConn;
	myConn=DriverManager.getConnection(dburl, user, passwd); 

	Statement stmt;

	String mySQL="select s_id from students where s_id='" + userID + "'and s_pwd='" + userPassword + "'";
	stmt = myConn.createStatement();
	stmt.executeUpdate(mySQL);
	ResultSet result = stmt.executeQuery(mySQL);
	if(result.next()){
		result.close();
		
		session.setAttribute("user",userID);
		response.sendRedirect("main.jsp");
		
	}else{  
		result.close();
		//%> <script> alert("로그인 실패"); history.go(-1); </script> <%  
		response.sendRedirect("login.jsp");
	}
	stmt.close();
	myConn.close(); 
}catch (Exception e){
	 out.println(e.toString());
}
%>
