if (!stc.empty() && stc.top() != '[')
            {
                stc.push(s[i]);
            }
            else
            {
                stc.pop();
            }
            break;