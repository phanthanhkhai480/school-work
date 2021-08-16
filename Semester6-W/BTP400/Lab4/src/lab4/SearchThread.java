package lab4;

class SearchThread extends Thread {
	private String search = "";
	private String[] dataArray;
	private String dataStored = "";
	private int count = 0;
	
	public SearchThread() {
		this.search = "";
		this.dataArray = null;
	}
	
	public SearchThread(String[] information, String m_contain) {
		this.dataArray = information;
		this.search = m_contain;
	}
	
	public void run() {
		if(this.search != null || this.search != "") {
			for(int a = 0; a < this.dataArray.length; a++) {
				if(this.dataArray[a].contains(this.search))	{
					dataStored+= this.dataArray[a] + ", ";
					count = getCount() + 1;
				}					
			}
		}	
	}
	
	public String getResult() {		return this.dataStored;		}

	public int getCount() {		return count;	}
}