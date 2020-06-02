<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*" %>
<html> <head><title> 수강신청 사용자 정보 수정 </title></head>
<body> <%@ include file="top.jsp" %>
<%
String new_Password=request.getParameter("new_pwd");
String new_address=request.getParameter("new_addr");

String dbdriver = "oracle.jdbc.driver.OracleDriver";
String dburl = "jdbc:oracle:thin:@localhost:1521:orcl";
String user = "db1510188";
String passwd = "test";

int result = 0;
PreparedStatement pstmt = null;
Connection myConn = null;
try{
	Class.forName(dbdriver);
	myConn=DriverManager.getConnection(dburl, user, passwd);
	
	pstmt = myConn.prepareStatement("update students set s_pwd=? where s_id='"+session_id+"'");
	pstmt.setString(1,new_Password);
	result = pstmt.executeUpdate();
	
	if(result == 1){
		%> <script> alert("수정 성공"); </script> <%  
	}else{
		%> <script> alert("result == 0"); </script> <%  
	}
}
catch(SQLException ex){
	String sMessage; 
	if (ex.getErrorCode() == 20002)
		sMessage="암호는 4자리 이상이어야 합니다";
	else if (ex.getErrorCode() == 20003)
		sMessage="암호에 공란은 입력되지 않습니다.";
	else sMessage="잠시 후 다시 시도하십시오";
	%> <script> alert(sMessage); </script> <% 
}%>
</body>
</html>

