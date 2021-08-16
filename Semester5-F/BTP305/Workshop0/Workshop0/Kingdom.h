/*! \file Kingdom.h
// \brief BTP200 Workshop 2: Dynamic Memory
// \details    Longer description of file
// \version 1.0
// \date 2018
// \author Eden Burton
// \copyright GNU Public License.
//
//
**/
#pragma once


/*!
 * a namespace dedicated to Seneca
 */
namespace sict {
	/*! A class which stores the attributes
	 * of a kingdom
	 */
	struct Kingdom {
		char m_name[32]; /*!< store the name of the kingdom */
		int m_population; /*!< stores the kingdom's population */

	   /*! an accessor which returns the kingdom's population
		  \return integer storing population
		*/
		int getPop() const { return m_population; }
	};
	//! function displays attributes of the kingdom
	/*!
	   \param a reference to an already defined kingdom
	*/
	void display(const Kingdom& a);

}
