' For compatibility with programs that use the old include files.

#INCLUDE THIS ONCE
%COMDLG32_INC = 1

#INCLUDE ONCE "commdlg.inc"

' // FindExtInFilter and FindFilterIndex are included in commdlg32.inc in the PB includes for PB 10.

FUNCTION FindExtInFilter (BYVAL sExt AS STRING, sDesc AS STRING, _
                          sExtList AS STRING) AS LONG

    LOCAL ix, iy  AS LONG
    LOCAL nc      AS LONG
    LOCAL sHeader AS STRING

    nc = PARSECOUNT(sExtList, ";")
    REDIM asExtList(1 TO nc) AS STRING
    PARSE sExtList, asExtList(), ";"

    FOR ix = 1 TO nc
        IF UCASE$(asExtList(ix)) = "*" + sExt THEN
            ' Got a match for our extension.
            IF ix > 1 THEN
                ' Rearrange extension list so our extension comes first.
                SWAP asExtList(1), asExtList(ix)
                sExtList = JOIN$(asExtList(), ";")
                REDIM asDesc(1 TO nc) AS STRING
                iy = INSTR(sDesc, "(")
                sHeader = LEFT$(sDesc, iy)
                sDesc = MID$(sDesc, iy + 1)
                sDesc = LEFT$(sDesc, -1)   ' trim off closing ")"
                PARSE sDesc, asDesc(), ","
                SWAP asDesc(1), asDesc(ix)
                sDesc = sHeader + JOIN$(asDesc(), ",") + ")"
            END IF
            FUNCTION = -1
            EXIT FUNCTION
        END IF
    NEXT

    FUNCTION = 0

END FUNCTION


FUNCTION FindFilterIndex (sFilter AS STRING, BYVAL sFileSpec AS STRING) AS LONG

    LOCAL ix, iy  AS LONG    ' indices
    LOCAL nc      AS LONG    ' item count
    LOCAL ixLevel AS LONG    ' filter index level
    LOCAL sExt    AS STRING  ' current file extension (if any)

    ' Get the default file extension in sExt.
    sFileSpec = RTRIM$(sFileSpec)
    ix = INSTR(-1, sFileSpec, ANY "\/:.")
    IF ix THEN
        IF MID$(sFileSpec, ix, 1) = "." THEN
            sExt = UCASE$(MID$(sFileSpec, ix))
        ELSE
            sExt = ".*"
        END IF
    END IF

    ' Parse the filter string out into an array, the better to work with it.
    sFilter = RTRIM$(sFilter, $NUL)
    nc = PARSECOUNT(sFilter, $NUL)
    IF (nc < 2) OR ((nc AND 1) = 1) THEN
        EXIT FUNCTION
    END IF
    REDIM asList(1 TO nc) AS STRING
    PARSE sFilter, asList(), $NUL
    ' ix = 1, e.g., "Source files (*.bas,*.inc)"
    ' ix = 2, e.g., "*.bas;*.inc"
    ' rinse, repeat.

    ' See which set of filters contains the default file extension.
    ' (If none, use the last one, assumed to be "*.*"). The filter set is
    ' rearranged as needed to make sure the default extension is the first
    ' one in the filter set, so Windows will apply the proper default if the
    ' user doesn't explicitly type in the extension.
    FOR ix = 1 TO nc - 1 STEP 2
        INCR ixLevel
        IF FindExtInFilter(sExt, asList(ix), asList(ix + 1)) THEN
            EXIT FOR
        END IF
    NEXT

    ' Rebuild the filter string, in case it was changed.
    sFilter = JOIN$(asList(), $NUL) + $NUL

    FUNCTION = ixLevel

END FUNCTION
