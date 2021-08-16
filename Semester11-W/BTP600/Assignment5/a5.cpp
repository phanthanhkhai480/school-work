#include "a5.h"
#include <iostream>
#include <string>

//Set to start in a ClassDesign State
FeatureStatus::FeatureStatus(){	
	this->fStates = new ClassDesign();
	this->theCode_ = "";
	this->theDesign_ = "";
	this->comment_ = "";
}

void FeatureStatus::setState(State* temp){	this->fStates = temp;	}

void FeatureStatus::accept(){	fStates->accept(*this);			}

void FeatureStatus::reject(){	this->fStates->reject(*this);	}

std::string FeatureStatus::stateName() const {	return this->fStates->stateName();		}

void FeatureStatus::update(const std::string& s){	this->fStates->update(s, *this);	}

void FeatureStatus::print() const{
	std::cout <<"-----------------------" << std::endl;
	std::cout << this->fStates->stateName() << std::endl;
	this->fStates->print(*this);
}



//ClassDesign
void ClassDesign::print(const FeatureStatus& feature) const
{	std::cout << feature.theDesign_ << std::endl;	}

void ClassDesign::update(const std::string& s, FeatureStatus& feature)
{	feature.theDesign_ = s;	}

void ClassDesign::accept(FeatureStatus& feature)
{	feature.setState(new CodeUpdate());	}



//CodeUpdate
void CodeUpdate::print(const FeatureStatus& feature) const
{	std::cout << feature.theCode_ << std::endl;	}

void CodeUpdate::update(const std::string& s, FeatureStatus& feature)
{	feature.theCode_ = s;	}

void CodeUpdate::accept(FeatureStatus& feature)
{	feature.setState(new UnitTest());	}

void CodeUpdate::reject(FeatureStatus& feature)
{	feature.setState(new ReDesignReq());	}



//ReDesignReq
void ReDesignReq::print(const FeatureStatus& feature) const
{
	std::cout << feature.comment_ << std::endl;
	std::cout << feature.theDesign_ << std::endl;
}

void ReDesignReq::update(const std::string& s, FeatureStatus& feature)
{	feature.comment_ = s;	}

void ReDesignReq::accept(FeatureStatus& feature)
{	feature.setState(new ClassDesign());	}

void ReDesignReq::reject(FeatureStatus& feature)
{	feature.setState(new CodeUpdate());	}



//UnitTest
void UnitTest::print(const FeatureStatus& feature) const
{
	std::cout << feature.theCode_ << std::endl;
	std::cout << feature.comment_ << std::endl;
}

void UnitTest::update(const std::string& s, FeatureStatus& feature)
{	feature.comment_ = feature.comment_ + "\n" + s;	}

void UnitTest::accept(FeatureStatus& feature)
{	feature.setState(new PullRequest());	}

void UnitTest::reject(FeatureStatus& feature)
{	feature.setState(new CodeFixReq());	}



//CodeFixReq
void CodeFixReq::print(const FeatureStatus& feature) const
{
	std::cout << feature.comment_ << std::endl;
	std::cout << feature.theCode_ << std::endl;
}

void CodeFixReq::update(const std::string& s, FeatureStatus& feature)
{	feature.comment_ = feature.comment_ + " " + s;	}

void CodeFixReq::accept(FeatureStatus& feature)
{	feature.setState(new CodeUpdate());	}

void CodeFixReq::reject(FeatureStatus& feature)
{	feature.setState(new ReDesignReq());	}



//PullRequest
void PullRequest::print(const FeatureStatus& feature) const
{
	std::cout << feature.theCode_ << std::endl;
	std::cout << feature.comment_ << std::endl;
}

void PullRequest::update(const std::string& s, FeatureStatus& feature)
{	feature.comment_ = s;	}

void PullRequest::accept(FeatureStatus& feature)
{	feature.setState(new ChangeAccepted());	}

void PullRequest::reject(FeatureStatus& feature)
{	feature.setState(new CodeFixReq());	}


void ChangeAccepted::print(const FeatureStatus& feature) const
{
	std::cout << feature.theDesign_ << std::endl;
	std::cout << feature.theCode_ << std::endl;
	std::cout << feature.comment_ << std::endl;
}

void ChangeAccepted::update(const std::string& s, FeatureStatus& feature)
{	feature.comment_ = "Change Accepted";	}
