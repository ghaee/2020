<%@ page language= "java" contentType ="text/html; charset=UTF-8" pageEncoding ="UTF-8"%> 
<%@ page import="java.sql.*" %>

<html><head><title>수강신청 조회</title></head>
<body>

<%	
	String s_id = (String)session.getAttribute("user");
	String c_id = request.getParameter("c_id");
	String tmp = request.getParameter("c_id_no").trim();
	int c_id_no = Integer.parseInt(tmp);
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
	
CallableStatement cstmt = myConn.prepareCall("{? = call DeleteEnroll(?,?,?)}");	
	cstmt.setString(2, s_id);
	cstmt.setString(3, c_id);
	cstmt.setInt(4,c_id_no);

	cstmt.registerOutParameter(1, java.sql.Types.VARCHAR);	
	try  {  	
		cstmt.execute();
		result = cstmt.getString(1);		
%>
<script>	
	alert("<%= result %>"); 
	location.href="select.jsp";
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
    