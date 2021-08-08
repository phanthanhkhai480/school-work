using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;

namespace Assignment
{
    public class Size
    {
        private string size_;
        public string size
        {
            get { return size_; }
            set { size_ = value; }
        }

        public Size(string _size)
        {
            this.size_ = _size;
        }
    }

    public class SizeManager
    {
        public ObservableCollection<Size> allSizes = new ObservableCollection<Size>();

        public SizeManager()
        {
            allSizes.Add(new Size("Small"));
            allSizes.Add(new Size("Medium"));    
            allSizes.Add(new Size("Large"));
            allSizes.Add(new Size("X-Large"));
            allSizes.Add(new Size("Party"));
        }
    }
}
