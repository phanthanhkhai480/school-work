#ifndef A5_H
#define A5_H

#include <string>
#include <iostream>

class FeatureStatus;

enum StateID {CLASSDESIGN,CODEUPATE,REDESIGNREQ,UNITTEST,CODEFIXREQ,PULLREQUEST,CHANGEACCEPTED};


//interface of State
class State {
protected:
	std::string name_;
public:
	State(){}
	virtual std::string stateName() const = 0;
	virtual void print(const FeatureStatus& feature) const = 0;
	virtual void update(const std::string& s, FeatureStatus& feature) = 0;
	virtual void accept(FeatureStatus& feature)= 0;
	virtual void reject(FeatureStatus& feature)= 0;
	~State(){}
};

class FeatureStatus {
	State* fStates;
	std::string theCode_;
	std::string comment_;
	std::string theDesign_;

	//use to avoid having multiple private
	//string around all other class.
	friend class ClassDesign;
	friend class CodeUpdate;
	friend class ReDesignReq;
	friend class UnitTest;
	friend class CodeFixReq;
	friend class PullRequest;
	friend class ChangeAccepted;
public:
	FeatureStatus(); 	//Must begin in a ClassDesign State
	void setState(State* temp);

	std::string stateName() const;
	void print() const;
	void update(const std::string& s);
	void accept();
	void reject();
};




class ClassDesign : public State {
	std::string name_;
public:
	ClassDesign() { 
		name_ = "Class Design"; 
	}
	std::string stateName() const { return name_; };
	void print(const FeatureStatus& feature) const;
	void update(const std::string& s, FeatureStatus& feature);
	void accept(FeatureStatus& feature);
	void reject(FeatureStatus& feature){}
};

class CodeUpdate : public State {
	std::string name_;
public:
	CodeUpdate() { 
		name_ = "Code Update"; 
	}
	std::string stateName() const { return name_; };
	void print(const FeatureStatus& feature) const;
	void update(const std::string& s, FeatureStatus& feature);
	void accept(FeatureStatus& feature);
	void reject(FeatureStatus& feature);
};

class ReDesignReq : public State {
	std::string name_;
public:
	ReDesignReq() { 
		name_ = "Redesign Requested"; 
	}
	std::string stateName() const { return name_; };
	void print(const FeatureStatus& feature) const;
	void update(const std::string& s, FeatureStatus& feature);
	void accept(FeatureStatus& feature);
	void reject(FeatureStatus& feature);
};

class UnitTest : public State {
	std::string name_;
public:
	UnitTest() { 
		name_ = "Unit Test"; 
	}
	std::string stateName() const { return name_; };
	void print(const FeatureStatus& feature) const;
	void update(const std::string& s, FeatureStatus& feature);
	void accept(FeatureStatus& feature);
	void reject(FeatureStatus& feature);
};

class CodeFixReq : public State {
	std::string name_;
public:
	CodeFixReq() {
		name_ = "Code Fix Requested"; 
	}
	std::string stateName() const { return name_; };
	void print(const FeatureStatus& feature) const;
	void update(const std::string& s, FeatureStatus& feature);
	void accept(FeatureStatus& feature);
	void reject(FeatureStatus& feature);
};

class PullRequest : public State {
	std::string name_;
public:
	PullRequest() { 
		name_ = "Pull Request"; 
	}
	std::string stateName() const { return name_; };
	void print(const FeatureStatus& feature) const;
	void update(const std::string& s, FeatureStatus& feature);
	void accept(FeatureStatus& feature);
	void reject(FeatureStatus& feature);
};

class ChangeAccepted : public State {
	std::string name_;
public:
	ChangeAccepted() { 
		name_ = "Change Accepted";
	}
	std::string stateName() const { return name_; };
	void print(const FeatureStatus& feature) const;
	void update(const std::string& s, FeatureStatus& feature);
	void accept(FeatureStatus& feature){}
	void reject(FeatureStatus& feature){}
};
#endif


