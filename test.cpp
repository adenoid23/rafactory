  inline void ClearNeedle()
  {
    needle_.clear();
    needle_ic_.clear();
  }

  inline void ClearHaystack()
  {
    if (haystack_) delete[] haystack_;
    haystack_ = nullptr;
  }

  void CaseSensitive(bool value) { case_sensitive_ = value; };

  bool FindNext()
  {
    if (case_sensitive_)
      return FindNext_CaseSensitive();
    else
      return FindNext_IgnoreCase();
  }

  bool FindFirst()
  {
    Reset();
    return FindNext();
  }

  inline char* Base() { return haystack_; }
  inline char* LastFound() { return last_found; }
  inline size_t LastFoundOffset() { return last_found - haystack_; }

  inline char* FindNextEndLine()
  {    
    current = last_found + needle_len_;
    while (current < end && 
      *current != char(13) && *current != char(10)) 
        ++current;
    return current;
  }
