<%@ page language= "java" contentType ="text/html; charset=UTF-8" pageEncoding ="UTF-8"%> 
<%@ page import="java.sql.*" %>

<html><head><title> 수강신청 입력 </title></head>
<body>

<%	
	String s_id = (String)session.getAttribute("user");
	String c_id = request.getParameter("c_id");
	String tmp = request.getParameter("c_id_no").trim();
	int c_id_no = Integer.parseInt(tmp);
	
	String time = request.getParameter("time");
	int idx = time.indexOf(",");
	int discard = time.indexOf("(");
	int discard2 = time.lastIndexOf("(");
	
	String day1 = time.substring(0,discard);
	String day2 = time.substring(idx+1,discard2);
	
	String day1_day = day1.replaceAll("[0-9:~]","");
	String day1_time = day1.replaceAll("[^0-9:~]","");
	String day1_stime = day1_time.substring(0,5);
	String day1_etime = day1_time.substring(6);
	
	String day2_day = day2.replaceAll("[0-9:~]","");
	String day2_time = day2.replaceAll("[^0-9:~]","");
	String day2_stime = day2_time.substring(0,5);
	String day2_etime = day2_time.substring(6);

%>
<%		 
out.println("c_id : " + c_id);
out.println("c_id_no" + c_id_no);
out.println("day1_day: "+ day1_day);
out.println("day1_stime: "+ day1_stime);
out.println("day1_etime: "+ day1_etime);


out.println("day2_day: "+ day2_day);
out.println("day2_stime: "+ day2_stime);
out.println("day2_etime: "+ day2_etime);

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

CallableStatement cstmt = myConn.prepareCall("{call InsertEnroll(?,?,?,?,?,?,?,?,?,?)}");	
cstmt.setString(1, s_id);
cstmt.setString(2, c_id);
cstmt.setInt(3,c_id_no);

cstmt.setString(4, day1_day);
cstmt.setString(5, day1_stime);
cstmt.setString(6, day1_etime);

cstmt.setString(7, day2_day);
cstmt.setString(8, day2_stime);
cstmt.setString(9, day2_etime);

cstmt.registerOutParameter(10, java.sql.Types.VARCHAR);	
try  {  	
	cstmt.execute();
	result = cstmt.getString(10);	
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
    