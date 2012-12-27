" Vim script examples
" Origin from http://www.ibm.com/developerworks/linux/library/l-vim-script-1/index.html


function! CapitalizeCenterAndMoveDown()
  s/\<./\u&/g
  center
  +1
endfunction

nmap <silent> \c :call CapitalizeCenterAndMoveDown()<cr>


"Create a text highlighting style that always stands out...
highlight STANDOUT term=bold cterm=bold gui=bold

"List of troublesome words...
let s:words = [
            \ "it's",  "its",
            \ "your",  "you're",
            \ "were",  "we're",   "where",
            \ "their", "they're", "there",
            \ "to",    "too",     "two"
            \ ]

"Build a Vim command to match troublesome words...
let s:words_matcher
            \ = 'match STANDOUT /\c\<\(' . join(s:words, '\|') . '\)\>/'

"Toggle word checking on or off...
function! WordCheck ()
    "Toggle the flag (or set it if it doesn't yet exist)...
    let w:check_words = exists('w:check_words') ? !w:check_words : 1

    "Turn match mechanism on/off, according to new state of flag...
    if w:check_words
        echo s:words_matcher
        exec s:words_matcher
    else
        match none
    endif
endfunction

"Use ;p to toggle checking...

nmap <silent>  ;p  :call WordCheck()<CR>

imap <silent> <C-D><C-D> <C-R>=strftime("%e %b %Y")<CR>
imap <silent> <C-T><C-T> <C-R>=strftime("%l:%M %p")<CR>

function! ExpurgateText (text)
    let expurgated_text = a:text

    for expletive in [ 'cagal', 'frak', 'gorram', 'mebs', 'zarking' ]
        let expurgated_text = substitute(expurgated_text, expletive, '[DELETED]', 'g')
    endfor

    return expurgated_text
endfunction

function! PrintArgs(arg1, arg2)
  echo 'Arg1: ' a:arg1
  echo 'Arg2: ' a:arg2
endfunction

function! CommentBlock(comment, ...)
  let introducer = a:0 >= 1 ? a:1 : "//"
  let box_char = a:0 >= 2 ? a:2 : "*"
  let width = a:0 >= 3 ? a:3 : strlen(a:comment) + 2

  return introducer . repeat(box_char, width) . "\<CR>"
        \ . introducer . " " . a:comment . "\<CR>"
        \ . introducer . repeat(box_char, width) . "\<CR>"
endfunction

imap <silent> ### <C-R>=CommentBlock(input("Enter comment:"), "#", "#")<CR>

