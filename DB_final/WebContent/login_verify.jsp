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

ResultSet rs = null;
Statement stmt = null;
Connection myConn = null;

try{
	Class.forName(dbdriver);
	myConn=DriverManager.getConnection(dburl, user, passwd); 


	String mySQL="select s_id from students where s_id='" + userID + "'and s_pwd='" + userPassword + "'";
	stmt = myConn.createStatement();
	stmt.executeUpdate(mySQL);
	rs = stmt.executeQuery(mySQL);
	if(rs.next()){
		rs.close();
		
		session.setAttribute("user",userID);
		response.sendRedirect("main.jsp");
		
	}else{  
		rs.close();
		%> <script> alert("로그인 실패"); history.go(-1); </script> <%  
		//response.sendRedirect("login.jsp");
	}
	
}catch (Exception e){
	 out.println(e.toString());
	 e.printStackTrace();
}finally{
    if(rs != null) try { rs.close(); } catch(SQLException ex) {}
    if(stmt != null) try { stmt.close(); } catch(SQLException ex) {}
    if(myConn != null) try { myConn.close(); } catch(SQLException ex) {}
}
%>
