/** \file myexception.h

   Define some boost exception tags and exception types.
 */
#if !defined phy1610_myexception_h_included
#define phy1610_myexception_h_included

#include <boost/exception/exception.hpp>
#include <boost/exception/info.hpp>
#include <string>
#include <unistd.h> // ssize_t

struct error : virtual std::exception, virtual boost::exception { } ;
struct regex_match_error : virtual error { } ;
struct file_open_error : virtual error { } ;
struct file_close_error : virtual error { } ;
struct file_write_error : virtual error { } ;
struct plan_create_error : virtual error { } ;
struct array_size_error : virtual error { } ;
struct array_not_square_error : virtual error { } ;
struct sendrecv_error : virtual error { } ;
struct mpiinitterm_error : virtual error { } ;
struct netcdf_error : virtual error { } ;
struct assert_error : virtual error { } ;

struct tag_match_input ;
typedef boost::error_info<tag_match_input,std::string> match_info ;

struct tag_match_re ;
typedef boost::error_info<tag_match_re,std::string> re_info ;

struct tag_open_error ;
typedef boost::error_info<tag_open_error,const char *> open_info ;

struct tag_file_descriptor ;
typedef boost::error_info<tag_file_descriptor,int> file_descriptor_info ;

struct tag_open_error_origin ;
typedef boost::error_info<tag_open_error_origin,std::string> name_info ;

struct tag_array_size_mismatch ;
typedef boost::error_info<tag_array_size_mismatch,size_t> asize_info ;

struct tag_write_size ;
typedef boost::error_info<tag_write_size,size_t> write_info ;

struct tag_write_offset ;
typedef boost::error_info<tag_write_offset,off_t> write_offset_info ;

struct tag_write_addr ;
typedef boost::error_info<tag_write_addr,const void *> write_addr_info ;

struct tag_write_result ;
typedef boost::error_info<tag_write_result,ssize_t> write_res_info ;

struct tag_array_numrows ;
typedef boost::error_info<tag_array_numrows,size_t> arows_info ;

struct tag_array_numcolumns ;
typedef boost::error_info<tag_array_numcolumns,size_t> acolumns_info ;

struct tag_mpirank ;
typedef boost::error_info<tag_mpirank,int> mpirank_info ;

struct tag_mpitag ;
typedef boost::error_info<tag_mpitag,int> mpitag_info ;

struct tag_mpierr ;
typedef boost::error_info<tag_mpierr,int> mpierr_info ;

struct tag_mpileft ;
typedef boost::error_info<tag_mpileft,int> mpileft_info ;

struct tag_mpiright ;
typedef boost::error_info<tag_mpiright,int> mpiright_info ;

struct tag_netcdf_errno ;
typedef boost::error_info<tag_netcdf_errno,int> netcdf_errno_info ;

struct tag_netcdf_strerror ;
typedef boost::error_info<tag_netcdf_strerror,const char *> netcdf_strerror_info ;

struct tag_intdata ;
typedef boost::error_info<tag_intdata,long> intdata_info ;

struct tag_intdata2 ;
typedef boost::error_info<tag_intdata2,long> intdata2_info ;

#define ASSERT_NO_ERROR (static_cast<void>(0))
#ifdef NDEBUG
   #define ASSERT_DATA_INT( expr, v1 )          ASSERT_NO_ERROR
   #define ASSERT_DATA_INT_INT( expr, v1, v2 )  ASSERT_NO_ERROR
#else
   #define ASSERT_DATA_INT( expr, v1 )          \
      ( (expr)                                  \
      ? ASSERT_NO_ERROR                         \
      : BOOST_THROW_EXCEPTION(                  \
            assert_error()                      \
               << intdata_info( v1 ) ) )

   #define ASSERT_DATA_INT_INT( expr, v1, v2 )  \
      ( (expr)                                  \
      ? ASSERT_NO_ERROR                         \
      : BOOST_THROW_EXCEPTION(                  \
            assert_error()                      \
               << intdata_info( v1 )            \
               << intdata2_info( v2 ) ) )
#endif

#endif
