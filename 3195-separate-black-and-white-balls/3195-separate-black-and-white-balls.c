long long minimumSteps(char* s) {
    long long ans = 0;
    char *s_ = s + strlen(s) - 1;

    // two-pointer approach:
    // have the front pointer point to the leftmost black ball
    // and the back pointer point to the rightmost white ball
    for (;;) {
        // point to the leftmost unseen black ball
        for (; *s == '0'; ++s);

        // point to the rightmost unseen white ball
        for (; s_ > s && *s_ == '1'; --s_);

        // verify if all the balls are already grouped appropriately
        if (s > s_) {
            break;
        }

        // compute the number of swaps that would be required
        ans += (s_ - s);

        // advance the pointers
        ++s; --s_;
    }
    
    return ans;
}