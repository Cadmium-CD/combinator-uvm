#ifndef UVMSC_BOOST_SMART_PTR_DETAIL_SP_COUNTED_BASE_HPP_INCLUDED
#define UVMSC_BOOST_SMART_PTR_DETAIL_SP_COUNTED_BASE_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  detail/sp_counted_base.hpp
//
//  Copyright 2005, 2006 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include <packages/boost/include/config.hpp>
#include <packages/boost/include/smart_ptr/detail/sp_has_sync.hpp>

#if defined( UVMSC_BOOST_SP_DISABLE_THREADS )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_nt.hpp>

#elif defined( UVMSC_BOOST_SP_USE_SPINLOCK )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_spin.hpp>

#elif defined( UVMSC_BOOST_SP_USE_PTHREADS )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_pt.hpp>

#elif defined( UVMSC_BOOST_DISABLE_THREADS ) && !defined( UVMSC_BOOST_SP_ENABLE_THREADS ) && !defined( UVMSC_BOOST_DISABLE_WIN32 )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_nt.hpp>

#elif defined( __GNUC__ ) && ( defined( __i386__ ) || defined( __x86_64__ ) )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_gcc_x86.hpp>

#elif defined( __GNUC__ ) && defined( __ia64__ ) && !defined( __INTEL_COMPILER )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_gcc_ia64.hpp>

#elif defined(__HP_aCC) && defined(__ia64)
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_acc_ia64.hpp>

#elif defined( __MWERKS__ ) && defined( __POWERPC__ )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_cw_ppc.hpp>

#elif defined( __GNUC__ ) && ( defined( __powerpc__ ) || defined( __ppc__ ) || defined( __ppc ) )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_gcc_ppc.hpp>

#elif defined( __GNUC__ ) && ( defined( __mips__ ) || defined( _mips ) )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_gcc_mips.hpp>

#elif defined( UVMSC_BOOST_SP_HAS_SYNC )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_sync.hpp>

#elif defined(__GNUC__) && ( defined( __sparcv9 ) || ( defined( __sparcv8 ) && ( __GNUC__ * 100 + __GNUC_MINOR__ >= 402 ) ) )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_gcc_sparc.hpp>

#elif defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32__ ) || defined(__CYGWIN__)
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_w32.hpp>

#elif defined( _AIX )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_aix.hpp>

#elif !defined( UVMSC_BOOST_HAS_THREADS )
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_nt.hpp>

#else
# include <packages/boost/include/smart_ptr/detail/sp_counted_base_spin.hpp>

#endif

#endif  // #ifndef UVMSC_BOOST_SMART_PTR_DETAIL_SP_COUNTED_BASE_HPP_INCLUDED
