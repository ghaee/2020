<%@ page language= "java" contentType ="text/html; charset=UTF-8" pageEncoding ="UTF-8"%> 
<%@ page import="java.sql.*" %>

<html><head><title> 수강신청 입력 </title></head>
<body>

<%	
	String s_id = (String)session.getAttribute("user");
	String c_id = request.getParameter("c_id");
	String tmp = request.getParameter("c_id_no").trim();
	int c_id_no = Integer.parseInt(tmp);
	String c_day = request.getParameter("c_day");
	String c_stime = request.getParameter("c_stime");
	String c_etime = request.getParameter("c_etime");
%>
<%		
	Connection myConn = null;    String	result = null;	
	String dbdriver = "oracle.jdbc.driver.OracleDriver";
	String dburl = "jdbc:oracle:thin:@localhost:1521:orcl";
	String user = "db1510188";
	String passwd = "test"; 

	try {
		Class.forName(dbdriver);
  	        myConn =  DriverManager.getConnection (dburl, user, passwd);
    } catch(SQLException ex) {
	     System.err.println("SQLException: " + ex.getMessage());
    }
	
CallableStatement cstmt = myConn.prepareCall("{call InsertEnroll(?,?,?,?,?,?,?)}");	
	cstmt.setString(1, s_id);
	cstmt.setString(2, c_id);
	cstmt.setInt(3,c_id_no);
	cstmt.setString(4, c_day);
	cstmt.setString(5, c_stime);
	cstmt.setString(6, c_etime);
	
	cstmt.registerOutParameter(7, java.sql.Types.VARCHAR);	
	try  {  	
		cstmt.execute();
		result = cstmt.getString(7);		
%>
<script>	
	alert("<%= result %>"); 
	location.href="insert.jsp";
</script>
<%		
	} catch(SQLException ex) {		
		 System.err.println("SQLException: " + ex.getMessage());
	}  
	finally {
	    if (cstmt != null) 
            try { myConn.commit(); cstmt.close();  myConn.close(); }
 	      catch(SQLException ex) { }
     }
%>
</form></body></html>
    