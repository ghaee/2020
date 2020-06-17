<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="java.sql.*" %>
<html> <head><title> 수강신청 사용자 정보 수정 </title></head>
<body> <%@ include file="top.jsp" %>
<%
String new_Password=request.getParameter("new_pwd");
String new_address=request.getParameter("new_addr");
String chk_Password = request.getParameter("chk_pwd");

//out.println(new_Password + chk_Password);
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
	

	pstmt = myConn.prepareStatement("update students set s_pwd=?,s_addr=? where s_id='"+session_id+"'");
	pstmt.setString(1,new_Password);
	pstmt.setString(2,new_address);
	result = pstmt.executeUpdate();
	
	if(result == 1){
		%> <script type="text/javascript"> alert("수정 성공"); location.href='update.jsp'; </script> <%  
	}else{
		%> <script type="text/javascript"> alert("result == 0"); history.go(-1); </script> <%  
	}
}
catch(SQLException ex){
	String sMessage; 
	if (ex.getErrorCode() == 20002)
		sMessage="암호는 5자리 이상이어야 합니다";
	else if (ex.getErrorCode() == 20003)
		sMessage="암호에 공란은 입력되지 않습니다.";
	else sMessage="잠시 후 다시 시도하십시오";
	
	response.setContentType("text/html; charset=UTF-8");
	 
	response.getWriter().print("<script>alert('"+sMessage+"'); location.href='update.jsp';</script>");

}finally{
    if(pstmt != null) try { pstmt.close(); } catch(SQLException ex) {}
    if(myConn != null) try { myConn.close(); } catch(SQLException ex) {}
}
%>

</body>
</html>

