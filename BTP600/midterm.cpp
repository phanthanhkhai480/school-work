
	class Video{
		private:
			int ownerID_;
			//true for processing, false for failed
			bool status_ = false;
			//true for uploaded, false for haven't upload
			bool uploaded_ = false;
			//make it public or private
			bool public_;
			std::string url_;
			std::string name_;
		public:
			Video(){
				ownID_ = 0;
				status_ = false;
				uploaded_ = false;
				public_ = false;
				url_ = '\0';
				name_ = '\0';
			}
			
			int getOwnerID() { return this->ownerID_; }
			bool getStatus() { return this->status_; }
			bool getUpload() { return this->uploaded_; }
			bool getPublic() { return this->public_; }
			std::string getUrl() { return this->url_; }
			std::string getName() { return this->name_; }
		
			setStatus(bool status){
				status_ = status;
			}
			setUpload(bool upload){
				uploaded_ = upload;
			}
			setPublic(bool set_){
				public_ = set_;
			}
			setURL(std::string url) {
				url_ = url;
			}
			
			setName(std::string name) {
				name_ = name;
			}
			
	}

	class VidStreamLogOn{
		private:
			int loginID_;
		public:
			int getOwnerID() { return this->loginID_; }
			virtual bool uploadVideo(Video mUpload_)=0;
			virtual void listingVideo()=0;
			virtual bool publicVideo(std::string mName_)=0;
			virtual bool watchingVideo(std::string mUrl_)=0;
	}
	
	class VidStreamWork : public VidStreamLogOn {
		Video* listVideo_;
		public:
			VidStreamWork() {	//set default value for all private member	}
			Video* getListVideo_() { return this->listVideo_; }
			
			bool uploadVideo(Video mUpload_){
				for(int a = 0; a < listVideo_.size(); a++){
					//check if there is a video existing
					if(mUpload_->getName() == listVideo_[a].name_){
						//video uploading			
					}		
				}
			}
			
			void listingVideo(){
				for(int a = 0; a < listVideo_.size(); a++){
					//list all the video in the account if they are uploaded
					//ensure it is the owner before do listing
					if(getOwnerID() == listVideo_[a]->getOwnerID()){
						if(listVideo_[a]->getUpload == true)
							std::cout << listVideo_[a]->getName << std::endl;
					}
				}
			}
			
			bool publicVideo(std::string mName_){
				for(int a = 0; a < listVideo_.size(); a++){
					//set status of public video as if the video is uploaded
					if(mName_ == listVideo_[a].name_){
						if(listVideo_[a]->getUpload)
							listVideo_[a]->setPublic(true);
					}
				}		
			}
			
			bool watchingVideo(std::string mUrl_){
				for(int a = 0; a < listVideo_.size(); a++){
					if(mUrl_ == listVideo_[a].url_){
						//play the video
					}
				}	
			}
	}
	
	
	//this is the proxy class, the data will be loaded here and
	//client can just accessing this class, without accessing the
	//original to save time loading
	class VidStreamProxy : public VidStreamLogOn{
		private:
			VidStreamWork vidWork_;
			Video videoCache_;
			Video* listCache_;
		public:
			VidStreamProxy{		//set default value for all private member	}
			VidStreamProxy(VidStreamWork temp_) { this->vidWork_ = temp_;}
			
			bool uploadVideo(Video mUpload_) {
				mUpload_ = videoCache_;
				//check status of the video
				if(videoCache_->getUpload() == false){
					for(int a = 0; a < listVideo_.size(); a++){
						//check if there is a video existing
						if(videoCache_->getName() == listVideo_[a].name_){
							vidWork_->uploadVideo();
							//if browser is closed, reuploaded
							if(browser.close()){
								videoCache_.status_ = false;
								listVideo_[a]->setStatus(videoCache_.status_);
								videoCache_.uploaded_ = false;
								listVideo_[a]->setUpload(videoCache_.uploaded_);
							}
							//if upload is finish, processing
							else{
								while(browser.processing()){
									videoCache_.status_ = true;
								}
								videoCache_.uploaded_ = true;
								listVideo_[a]->setStatus(videoCache_.status_);
								listVideo_[a]->setUpload(videoCache_.uploaded_);
								listVideo_[a]->setPublic(videoCache_.public_);
								listVideo_[a]->setURL(videoCache_.url_);
								listVideo_[a]->setName(videoCache_.name_);
							}								
						}
					}
				}				
			}
			
			void listingVideo() {
				if(listCache_ == null)
					listCache_ = vidWork_.getListVideo_();
			}
			
			bool publicVideo(std::string mName_) {
				for(int a = 0; a < listCache_.size(); a++){
					//set status of public video as if the video is uploaded
					if(mName_ == listCache_[a].name_){
						if(listCache_[a]->getUpload)
							videoCache_ = listCache_[a];
							listCache_[a]->setPublic(true);
					}
				}	
			}
			
			bool watchingVideo(std::string mUrl_) {
				for(int a = 0; a < listCache_.size(); a++){
					if(mUrl_ == listCache_[a].url_){
						
						//video is still processing
						if(listCache_[a]->getStatus)
							std::coud << "Video is still processing" << std::endl;
						
						else {
							//play video as an owner
							if(getOwnerID() == listCache_[a]->getOwnerID())
								videoCache_ = listCache_[a];
								//play the video
							
							else {
								//play video as a public video
								if(listCache_[a]->getPublic())
									videoCache_ = listCache_[a];
									//play the video
								else
									std::coud << "404: Video not found or not publicly accessible" << std::endl;
							}
						}	
					}
				}	
			}
			
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	