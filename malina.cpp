    if (needle.size() > 0) SetNeedle(needle);
  }

  BMH_Search(const char* haystack, size_t length, 
    const std::string& needle = "")
  {
    Init();//good
    SetHayStack(haystack, length);
    if (needle.size() > 0) SetNeedle(needle);
  }

  ~BMH_Search()
  {
    ClearHaystack();
    ClearNeedle();
  }

  void Reset()
  {
    current = haystack_; 
    last_found = nullptr;
  }

  void SetNeedle(const std::string& needle)
  {
    ClearNeedle();
    needle_len_ = static_cast<int>(needle.size());
    if (!needle_len_) return;

    //case sensitive needle
    needle_len_less1 = needle_len_ - 1;
    needle_.clear();
    needle_.reserve(needle_len_);
    for (const char& c : needle) needle_.push_back(static_cast<uint8_t>(c));
    
    //case insensitive needle
    needle_ic_ = needle_;
    for (std::vector< uint8_t>::iterator ui = needle_ic_.begin(); ui != needle_ic_.end(); ++ui)
      *ui = case_table[*ui];
