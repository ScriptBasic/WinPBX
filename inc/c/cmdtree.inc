' ########################################################################################
' Microsoft Windows
' File: cmdtree.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CMDTREE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oledb.inc"

'#ifdef _WIN64
'#include <pshpack8.h>   // 8-byte structure packing
'#else
'#include <pshpack2.h>   // 2-byte structure packing
'#endif

#IF NOT %DEF(%CommandTreeStructureDefinitions_INTERFACE_DEFINED)
%CommandTreeStructureDefinitions_INTERFACE_DEFINED = 1

'typedef WORD DBCOMMANDOP;

' DBCOMMANDOPENUM
%DBOP_scalar_constant                       = 0
%DBOP_DEFAULT                               = %DBOP_scalar_constant                + 1
%DBOP_NULL                                  = %DBOP_DEFAULT                        + 1
%DBOP_bookmark_name                         = %DBOP_NULL                           + 1
%DBOP_catalog_name                          = %DBOP_bookmark_name                  + 1
%DBOP_column_name                           = %DBOP_catalog_name                   + 1
%DBOP_schema_name                           = %DBOP_column_name                    + 1
%DBOP_outall_name                           = %DBOP_schema_name                    + 1
%DBOP_qualifier_name                        = %DBOP_outall_name                    + 1
%DBOP_qualified_column_name                 = %DBOP_qualifier_name                 + 1
%DBOP_table_name                            = %DBOP_qualified_column_name          + 1
%DBOP_nested_table_name                     = %DBOP_table_name                     + 1
%DBOP_nested_column_name                    = %DBOP_nested_table_name              + 1
%DBOP_row                                   = %DBOP_nested_column_name             + 1
%DBOP_table                                 = %DBOP_row                            + 1
%DBOP_sort                                  = %DBOP_table                          + 1
%DBOP_distinct                              = %DBOP_sort                           + 1
%DBOP_distinct_order_preserving             = %DBOP_distinct                       + 1
%DBOP_alias                                 = %DBOP_distinct_order_preserving      + 1
%DBOP_cross_join                            = %DBOP_alias                          + 1
%DBOP_union_join                            = %DBOP_cross_join                     + 1
%DBOP_inner_join                            = %DBOP_union_join                     + 1
%DBOP_left_semi_join                        = %DBOP_inner_join                     + 1
%DBOP_right_semi_join                       = %DBOP_left_semi_join                 + 1
%DBOP_left_anti_semi_join                   = %DBOP_right_semi_join                + 1
%DBOP_right_anti_semi_join                  = %DBOP_left_anti_semi_join            + 1
%DBOP_left_outer_join                       = %DBOP_right_anti_semi_join           + 1
%DBOP_right_outer_join                      = %DBOP_left_outer_join                + 1
%DBOP_full_outer_join                       = %DBOP_right_outer_join               + 1
%DBOP_natural_join                          = %DBOP_full_outer_join                + 1
%DBOP_natural_left_outer_join               = %DBOP_natural_join                   + 1
%DBOP_natural_right_outer_join              = %DBOP_natural_left_outer_join        + 1
%DBOP_natural_full_outer_join               = %DBOP_natural_right_outer_join       + 1
%DBOP_set_intersection                      = %DBOP_natural_full_outer_join        + 1
%DBOP_set_union                             = %DBOP_set_intersection               + 1
%DBOP_set_left_difference                   = %DBOP_set_union                      + 1
%DBOP_set_right_difference                  = %DBOP_set_left_difference            + 1
%DBOP_set_anti_difference                   = %DBOP_set_right_difference           + 1
%DBOP_bag_intersection                      = %DBOP_set_anti_difference            + 1
%DBOP_bag_union                             = %DBOP_bag_intersection               + 1
%DBOP_bag_left_difference                   = %DBOP_bag_union                      + 1
%DBOP_bag_right_difference                  = %DBOP_bag_left_difference            + 1
%DBOP_bag_anti_difference                   = %DBOP_bag_right_difference           + 1
%DBOP_division                              = %DBOP_bag_anti_difference            + 1
%DBOP_relative_sampling                     = %DBOP_division                       + 1
%DBOP_absolute_sampling                     = %DBOP_relative_sampling              + 1
%DBOP_transitive_closure                    = %DBOP_absolute_sampling              + 1
%DBOP_recursive_union                       = %DBOP_transitive_closure             + 1
%DBOP_aggregate                             = %DBOP_recursive_union                + 1
%DBOP_remote_table                          = %DBOP_aggregate                      + 1
%DBOP_select                                = %DBOP_remote_table                   + 1
%DBOP_order_preserving_select               = %DBOP_select                         + 1
%DBOP_project                               = %DBOP_order_preserving_select        + 1
%DBOP_project_order_preserving              = %DBOP_project                        + 1
%DBOP_top                                   = %DBOP_project_order_preserving       + 1
%DBOP_top_percent                           = %DBOP_top                            + 1
%DBOP_top_plus_ties                         = %DBOP_top_percent                    + 1
%DBOP_top_percent_plus_ties                 = %DBOP_top_plus_ties                  + 1
%DBOP_rank                                  = %DBOP_top_percent_plus_ties          + 1
%DBOP_rank_ties_equally                     = %DBOP_rank                           + 1
%DBOP_rank_ties_equally_and_skip            = %DBOP_rank_ties_equally              + 1
%DBOP_navigate                              = %DBOP_rank_ties_equally_and_skip     + 1
%DBOP_nesting                               = %DBOP_navigate                       + 1
%DBOP_unnesting                             = %DBOP_nesting                        + 1
%DBOP_nested_apply                          = %DBOP_unnesting                      + 1
%DBOP_cross_tab                             = %DBOP_nested_apply                   + 1
%DBOP_is_NULL                               = %DBOP_cross_tab                      + 1
%DBOP_is_NOT_NULL                           = %DBOP_is_NULL                        + 1
%DBOP_equal                                 = %DBOP_is_NOT_NULL                    + 1
%DBOP_not_equal                             = %DBOP_equal                          + 1
%DBOP_less                                  = %DBOP_not_equal                      + 1
%DBOP_less_equal                            = %DBOP_less                           + 1
%DBOP_greater                               = %DBOP_less_equal                     + 1
%DBOP_greater_equal                         = %DBOP_greater                        + 1
%DBOP_equal_all                             = %DBOP_greater_equal                  + 1
%DBOP_not_equal_all                         = %DBOP_equal_all                      + 1
%DBOP_less_all                              = %DBOP_not_equal_all                  + 1
%DBOP_less_equal_all                        = %DBOP_less_all                       + 1
%DBOP_greater_all                           = %DBOP_less_equal_all                 + 1
%DBOP_greater_equal_all                     = %DBOP_greater_all                    + 1
%DBOP_equal_any                             = %DBOP_greater_equal_all              + 1
%DBOP_not_equal_any                         = %DBOP_equal_any                      + 1
%DBOP_less_any                              = %DBOP_not_equal_any                  + 1
%DBOP_less_equal_any                        = %DBOP_less_any                       + 1
%DBOP_greater_any                           = %DBOP_less_equal_any                 + 1
%DBOP_greater_equal_any                     = %DBOP_greater_any                    + 1
%DBOP_anybits                               = %DBOP_greater_equal_any              + 1
%DBOP_allbits                               = %DBOP_anybits                        + 1
%DBOP_anybits_any                           = %DBOP_allbits                        + 1
%DBOP_allbits_any                           = %DBOP_anybits_any                    + 1
%DBOP_anybits_all                           = %DBOP_allbits_any                    + 1
%DBOP_allbits_all                           = %DBOP_anybits_all                    + 1
%DBOP_between                               = %DBOP_allbits_all                    + 1
%DBOP_between_unordered                     = %DBOP_between                        + 1
%DBOP_match                                 = %DBOP_between_unordered              + 1
%DBOP_match_unique                          = %DBOP_match                          + 1
%DBOP_match_partial                         = %DBOP_match_unique                   + 1
%DBOP_match_partial_unique                  = %DBOP_match_partial                  + 1
%DBOP_match_full                            = %DBOP_match_partial_unique           + 1
%DBOP_match_full_unique                     = %DBOP_match_full                     + 1
%DBOP_scalar_parameter                      = %DBOP_match_full_unique              + 1
%DBOP_scalar_function                       = %DBOP_scalar_parameter               + 1
%DBOP_plus                                  = %DBOP_scalar_function                + 1
%DBOP_minus                                 = %DBOP_plus                           + 1
%DBOP_times                                 = %DBOP_minus                          + 1
%DBOP_over                                  = %DBOP_times                          + 1
%DBOP_div                                   = %DBOP_over                           + 1
%DBOP_modulo                                = %DBOP_div                            + 1
%DBOP_power                                 = %DBOP_modulo                         + 1
%DBOP_like                                  = %DBOP_power                          + 1
%DBOP_sounds_like                           = %DBOP_like                           + 1
%DBOP_like_any                              = %DBOP_sounds_like                    + 1
%DBOP_like_all                              = %DBOP_like_any                       + 1
%DBOP_is_INVALID                            = %DBOP_like_all                       + 1
%DBOP_is_TRUE                               = %DBOP_is_INVALID                     + 1
%DBOP_is_FALSE                              = %DBOP_is_TRUE                        + 1
%DBOP_and                                   = %DBOP_is_FALSE                       + 1
%DBOP_or                                    = %DBOP_and                            + 1
%DBOP_xor                                   = %DBOP_or                             + 1
%DBOP_equivalent                            = %DBOP_xor                            + 1
%DBOP_not                                   = %DBOP_equivalent                     + 1
%DBOP_implies                               = %DBOP_not                            + 1
%DBOP_overlaps                              = %DBOP_implies                        + 1
%DBOP_case_condition                        = %DBOP_overlaps                       + 1
%DBOP_case_value                            = %DBOP_case_condition                 + 1
%DBOP_nullif                                = %DBOP_case_value                     + 1
%DBOP_cast                                  = %DBOP_nullif                         + 1
%DBOP_coalesce                              = %DBOP_cast                           + 1
%DBOP_position                              = %DBOP_coalesce                       + 1
%DBOP_extract                               = %DBOP_position                       + 1
%DBOP_char_length                           = %DBOP_extract                        + 1
%DBOP_octet_length                          = %DBOP_char_length                    + 1
%DBOP_bit_length                            = %DBOP_octet_length                   + 1
%DBOP_substring                             = %DBOP_bit_length                     + 1
%DBOP_upper                                 = %DBOP_substring                      + 1
%DBOP_lower                                 = %DBOP_upper                          + 1
%DBOP_trim                                  = %DBOP_lower                          + 1
%DBOP_translate                             = %DBOP_trim                           + 1
%DBOP_convert                               = %DBOP_translate                      + 1
%DBOP_string_concat                         = %DBOP_convert                        + 1
%DBOP_current_date                          = %DBOP_string_concat                  + 1
%DBOP_current_time                          = %DBOP_current_date                   + 1
%DBOP_current_timestamp                     = %DBOP_current_time                   + 1
%DBOP_content_select                        = %DBOP_current_timestamp              + 1
%DBOP_content                               = %DBOP_content_select                 + 1
%DBOP_content_freetext                      = %DBOP_content                        + 1
%DBOP_content_proximity                     = %DBOP_content_freetext               + 1
%DBOP_content_vector_or                     = %DBOP_content_proximity              + 1
%DBOP_delete                                = %DBOP_content_vector_or              + 1
%DBOP_update                                = %DBOP_delete                         + 1
%DBOP_insert                                = %DBOP_update                         + 1
%DBOP_min                                   = %DBOP_insert                         + 1
%DBOP_max                                   = %DBOP_min                            + 1
%DBOP_count                                 = %DBOP_max                            + 1
%DBOP_sum                                   = %DBOP_count                          + 1
%DBOP_avg                                   = %DBOP_sum                            + 1
%DBOP_any_sample                            = %DBOP_avg                            + 1
%DBOP_stddev                                = %DBOP_any_sample                     + 1
%DBOP_stddev_pop                            = %DBOP_stddev                         + 1
%DBOP_var                                   = %DBOP_stddev_pop                     + 1
%DBOP_var_pop                               = %DBOP_var                            + 1
%DBOP_first                                 = %DBOP_var_pop                        + 1
%DBOP_last                                  = %DBOP_first                          + 1
%DBOP_in                                    = %DBOP_last                           + 1
%DBOP_exists                                = %DBOP_in                             + 1
%DBOP_unique                                = %DBOP_exists                         + 1
%DBOP_subset                                = %DBOP_unique                         + 1
%DBOP_proper_subset                         = %DBOP_subset                         + 1
%DBOP_superset                              = %DBOP_proper_subset                  + 1
%DBOP_proper_superset                       = %DBOP_superset                       + 1
%DBOP_disjoint                              = %DBOP_proper_superset                + 1
%DBOP_pass_through                          = %DBOP_disjoint                       + 1
%DBOP_defined_by_GUID                       = %DBOP_pass_through                   + 1
%DBOP_text_command                          = %DBOP_defined_by_GUID                + 1
%DBOP_SQL_select                            = %DBOP_text_command                   + 1
%DBOP_prior_command_tree                    = %DBOP_SQL_select                     + 1
%DBOP_add_columns                           = %DBOP_prior_command_tree             + 1
%DBOP_column_list_anchor                    = %DBOP_add_columns                    + 1
%DBOP_column_list_element                   = %DBOP_column_list_anchor             + 1
%DBOP_command_list_anchor                   = %DBOP_column_list_element            + 1
%DBOP_command_list_element                  = %DBOP_command_list_anchor            + 1
%DBOP_from_list_anchor                      = %DBOP_command_list_element           + 1
%DBOP_from_list_element                     = %DBOP_from_list_anchor               + 1
%DBOP_project_list_anchor                   = %DBOP_from_list_element              + 1
%DBOP_project_list_element                  = %DBOP_project_list_anchor            + 1
%DBOP_row_list_anchor                       = %DBOP_project_list_element           + 1
%DBOP_row_list_element                      = %DBOP_row_list_anchor                + 1
%DBOP_scalar_list_anchor                    = %DBOP_row_list_element               + 1
%DBOP_scalar_list_element                   = %DBOP_scalar_list_anchor             + 1
%DBOP_set_list_anchor                       = %DBOP_scalar_list_element            + 1
%DBOP_set_list_element                      = %DBOP_set_list_anchor                + 1
%DBOP_sort_list_anchor                      = %DBOP_set_list_element               + 1
%DBOP_sort_list_element                     = %DBOP_sort_list_anchor               + 1
%DBOP_alter_character_set                   = %DBOP_sort_list_element              + 1
%DBOP_alter_collation                       = %DBOP_alter_character_set            + 1
%DBOP_alter_domain                          = %DBOP_alter_collation                + 1
%DBOP_alter_index                           = %DBOP_alter_domain                   + 1
%DBOP_alter_procedure                       = %DBOP_alter_index                    + 1
%DBOP_alter_schema                          = %DBOP_alter_procedure                + 1
%DBOP_alter_table                           = %DBOP_alter_schema                   + 1
%DBOP_alter_trigger                         = %DBOP_alter_table                    + 1
%DBOP_alter_view                            = %DBOP_alter_trigger                  + 1
%DBOP_coldef_list_anchor                    = %DBOP_alter_view                     + 1
%DBOP_coldef_list_element                   = %DBOP_coldef_list_anchor             + 1
%DBOP_create_assertion                      = %DBOP_coldef_list_element            + 1
%DBOP_create_character_set                  = %DBOP_create_assertion               + 1
%DBOP_create_collation                      = %DBOP_create_character_set           + 1
%DBOP_create_domain                         = %DBOP_create_collation               + 1
%DBOP_create_index                          = %DBOP_create_domain                  + 1
%DBOP_create_procedure                      = %DBOP_create_index                   + 1
%DBOP_create_schema                         = %DBOP_create_procedure               + 1
%DBOP_create_synonym                        = %DBOP_create_schema                  + 1
%DBOP_create_table                          = %DBOP_create_synonym                 + 1
%DBOP_create_temporary_table                = %DBOP_create_table                   + 1
%DBOP_create_translation                    = %DBOP_create_temporary_table         + 1
%DBOP_create_trigger                        = %DBOP_create_translation             + 1
%DBOP_create_view                           = %DBOP_create_trigger                 + 1
%DBOP_drop_assertion                        = %DBOP_create_view                    + 1
%DBOP_drop_character_set                    = %DBOP_drop_assertion                 + 1
%DBOP_drop_collation                        = %DBOP_drop_character_set             + 1
%DBOP_drop_domain                           = %DBOP_drop_collation                 + 1
%DBOP_drop_index                            = %DBOP_drop_domain                    + 1
%DBOP_drop_procedure                        = %DBOP_drop_index                     + 1
%DBOP_drop_schema                           = %DBOP_drop_procedure                 + 1
%DBOP_drop_synonym                          = %DBOP_drop_schema                    + 1
%DBOP_drop_table                            = %DBOP_drop_synonym                   + 1
%DBOP_drop_translation                      = %DBOP_drop_table                     + 1
%DBOP_drop_trigger                          = %DBOP_drop_translation               + 1
%DBOP_drop_view                             = %DBOP_drop_trigger                   + 1
%DBOP_foreign_key                           = %DBOP_drop_view                      + 1
%DBOP_grant_privileges                      = %DBOP_foreign_key                    + 1
%DBOP_index_list_anchor                     = %DBOP_grant_privileges               + 1
%DBOP_index_list_element                    = %DBOP_index_list_anchor              + 1
%DBOP_primary_key                           = %DBOP_index_list_element             + 1
%DBOP_property_list_anchor                  = %DBOP_primary_key                    + 1
%DBOP_property_list_element                 = %DBOP_property_list_anchor           + 1
%DBOP_referenced_table                      = %DBOP_property_list_element          + 1
%DBOP_rename_object                         = %DBOP_referenced_table               + 1
%DBOP_revoke_privileges                     = %DBOP_rename_object                  + 1
%DBOP_schema_authorization                  = %DBOP_revoke_privileges              + 1
%DBOP_unique_key                            = %DBOP_schema_authorization           + 1
%DBOP_scope_list_anchor                     = %DBOP_unique_key                     + 1
%DBOP_scope_list_element                    = %DBOP_scope_list_anchor              + 1
%DBOP_content_table                         = %DBOP_scope_list_element             + 1

'#IF %DEF(%DBINITCONSTANTS)
$DBGUID_LIKE_SQL                       = GUID$("{C8B521F6-5CF3-11CE-ADE5-00AA0044773D}")
$DBGUID_LIKE_DOS                       = GUID$("{C8B521F7-5CF3-11CE-ADE5-00AA0044773D}")
$DBGUID_LIKE_OFS                       = GUID$("{C8B521F8-5CF3-11CE-ADE5-00AA0044773D}")
$DBGUID_LIKE_MAPI                      = GUID$("{C8B521F9-5CF3-11CE-ADE5-00AA0044773D}")
'#ENDIF   ' // DBINITCONSTANTS


#ENDIF   ' /* __CommandTreeStructureDefinitions_INTERFACE_DEFINED__ */

' ########################################################################################
' ICommandTree interface
' IID = 0C733A87-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommandTree_INTERFACE_DEFINED)
%ICommandTree_INTERFACE_DEFINED = 1

'typedef DWORD DBCOMMANDREUSE;

' DBCOMMANDREUSEENUM
%DBCOMMANDREUSE_NONE                        = 0
%DBCOMMANDREUSE_PROPERTIES                  = &H1
%DBCOMMANDREUSE_PARAMETERS                  = &H2

'typedef DWORD DBVALUEKIND;

' DBVALUEKINDENUM
%DBVALUEKIND_BYGUID                         = 256
%DBVALUEKIND_COLDESC                        = %DBVALUEKIND_BYGUID                  + 1
%DBVALUEKIND_ID                             = %DBVALUEKIND_COLDESC                 + 1
%DBVALUEKIND_CONTENT                        = %DBVALUEKIND_ID                      + 1
%DBVALUEKIND_CONTENTVECTOR                  = %DBVALUEKIND_CONTENT                 + 1
%DBVALUEKIND_GROUPINFO                      = %DBVALUEKIND_CONTENTVECTOR           + 1
%DBVALUEKIND_PARAMETER                      = %DBVALUEKIND_GROUPINFO               + 1
%DBVALUEKIND_PROPERTY                       = %DBVALUEKIND_PARAMETER               + 1
%DBVALUEKIND_SETFUNC                        = %DBVALUEKIND_PROPERTY                + 1
%DBVALUEKIND_SORTINFO                       = %DBVALUEKIND_SETFUNC                 + 1
%DBVALUEKIND_TEXT                           = %DBVALUEKIND_SORTINFO                + 1
%DBVALUEKIND_COMMAND                        = %DBVALUEKIND_TEXT                    + 1
%DBVALUEKIND_MONIKER                        = %DBVALUEKIND_COMMAND                 + 1
%DBVALUEKIND_ROWSET                         = %DBVALUEKIND_MONIKER                 + 1
%DBVALUEKIND_LIKE                           = %DBVALUEKIND_ROWSET                  + 1
%DBVALUEKIND_CONTENTPROXIMITY               = %DBVALUEKIND_LIKE                    + 1
%DBVALUEKIND_IDISPATCH                      = 9
%DBVALUEKIND_IUNKNOWN                       = 13
%DBVALUEKIND_EMPTY                          = 0
%DBVALUEKIND_NULL                           = 1
%DBVALUEKIND_I2                             = 2
%DBVALUEKIND_I4                             = 3
%DBVALUEKIND_R4                             = 4
%DBVALUEKIND_R8                             = 5
%DBVALUEKIND_CY                             = 6
%DBVALUEKIND_DATE                           = 7
%DBVALUEKIND_BSTR                           = 8
%DBVALUEKIND_ERROR                          = 10
%DBVALUEKIND_BOOL                           = 11
%DBVALUEKIND_VARIANT                        = 12
%DBVALUEKIND_VECTOR                         = &H1000
%DBVALUEKIND_ARRAY                          = &H2000
%DBVALUEKIND_BYREF                          = &H4000
%DBVALUEKIND_I1                             = 16
%DBVALUEKIND_UI1                            = 17
%DBVALUEKIND_UI2                            = 18
%DBVALUEKIND_UI4                            = %DBVALUEKIND_UI2                     + 1
%DBVALUEKIND_I8                             = %DBVALUEKIND_UI4                     + 1
%DBVALUEKIND_UI8                            = %DBVALUEKIND_I8                      + 1
%DBVALUEKIND_GUID                           = 72
%DBVALUEKIND_BYTES                          = 128
%DBVALUEKIND_STR                            = 129
%DBVALUEKIND_WSTR                           = 130
%DBVALUEKIND_NUMERIC                        = 131
%DBVALUEKIND_DBDATE                         = 133
%DBVALUEKIND_DBTIME                         = 134
%DBVALUEKIND_DBTIMESTAMP                    = 135
%DBVALUEKIND_PROBABILISTIC                  = 136
%DBVALUEKIND_RELEVANTDOCUMENT               = 137

' // Size = 24 bytes
TYPE DBBYGUID WORD
   pbInfo AS BYTE PTR   ' BYTE     // extra node information, provider-specific
   cbInfo AS DWORD      ' DBLENGTH // size of the data in pbInfo
   guid   AS GUID       ' GUID     // this node's GUID
END TYPE

%GENERATE_METHOD_EXACT   = 0
%GENERATE_METHOD_PREFIX  = 1
%GENERATE_METHOD_INFLECT = 2

' // Size = 16 bytes
TYPE DBCONTENT WORD
   pwszPhrase       AS WSTRINGZ PTR   ' LPOLESTR // text
   dwGenerateMethod AS DWORD          ' DWORD    // exact, prefix, stemmed
   lWeight          AS LONG           ' LONG     // weight of node
   lcid             AS DWORD          ' LCID     // locale
END TYPE

%SCOPE_FLAG_MASK    = &H000000ff???
%SCOPE_FLAG_INCLUDE = &H00000001???
%SCOPE_FLAG_DEEP    = &H00000002???
%SCOPE_TYPE_MASK    = &Hffffff00???
%SCOPE_TYPE_WINPATH = &H00000100???
%SCOPE_TYPE_VPATH   = &H00000200???

' // Size = 12 bytes
TYPE DBCONTENTSCOPE WORD
   dwFlags          AS DWORD
   rgpwszTagName    AS WSTRINGZ PTR   ' LPOLESTR * [array]
   pwszElementValue AS WSTRINGZ PTR   ' LPOLESTR
END TYPE

' // Size = 8 bytes
TYPE DBCONTENTTABLE WORD
   pwszMachine AS WSTRINGZ PTR   ' LPOLESTR
   pwszCatalog AS WSTRINGZ PTR   ' LPOLESTR
END TYPE

%PROPID_QUERY_RANKVECTOR = &H2
%PROPID_QUERY_RANK       = &H3
%PROPID_QUERY_HITCOUNT   = &H4
%PROPID_QUERY_ALL        = &H6
%PROPID_STG_CONTENTS     = &H13
%VECTOR_RANK_MIN         = 0
%VECTOR_RANK_MAX         = 1
%VECTOR_RANK_INNER       = 2
%VECTOR_RANK_DICE        = 3
%VECTOR_RANK_JACCARD     = 4

' // Size = 8 bytes
TYPE DBCONTENTVECTOR WORD
   lWeight         AS LONG    ' LONG // node weight
   dwRankingMethod AS DWORD   ' DWORD // jaccard, dice, etc.
END TYPE

' // Size = 4 bytes
TYPE DBGROUPINFO WORD
   lcid AS DWORD   ' LCID // local ID for text portion of query
END TYPE

' // Size = 22 bytes
' // Note: In Windows 64 bits, this structure must be DWORD aligned, with a size of 24 bytes.
TYPE DBPARAMETER WORD
   pwszName    AS WSTRINGZ PTR     ' LPOLESTR     // parameter name
   pTypeInfo   AS DWORD            ' ITypeInfo *  // if not a null pointer, type is described by the ITypeInfo
   pNum        AS DB_NUMERIC PTR   ' DB_NUMERIC * // Structure describing the precision, scale and value of the numeric value.
   cbMaxLength AS DWORD            ' DBLENGTH     // the maximum length of the parameter
   dwFlags     AS DWORD            ' DBPARAMFLAGS // bitmask describing parameter characteristics
   wType       AS WORD             ' DBTYPE       // type of the parameter
END TYPE

%DBSETFUNC_NONE     = &H0
%DBSETFUNC_ALL      = &H1
%DBSETFUNC_DISTINCT = &H2

' // Size = 4 bytes
TYPE DBSETFUNC WORD
   dwSetQuantifier AS DWORD   ' DWORD // which aggregation method to use
END TYPE

' // Size = 8 bytes
TYPE DBSORTINFO WORD
   fDesc AS LONG    ' BOOL // TRUE = ascending, FALSE = descending
   lcid  AS DWORD   ' LCID // locale identifier
END TYPE

' // Size = 28 bytes
TYPE DBTEXT WORD
   pwszText       AS WSTRINGZ PTR   ' LPOLESTR
   ulErrorLocator AS DWORD          ' ULONG // set by validation routines
   ulTokenLength  AS DWORD          ' ULONG // length of offending token
   guidDialect    AS GUID           ' GUID // GUID of the language and dialect
END TYPE

' // Size = 20 bytes
TYPE DBLIKE WORD
   lWeight     AS LONG   ' LONG // weight on the dbop_like node
   guidDialect AS GUID   ' GUID // system to use for "likeness". E.g. Reg. Ex.
END TYPE

%PROXIMITY_UNIT_WORD      = 0
%PROXIMITY_UNIT_SENTENCE  = 1
%PROXIMITY_UNIT_PARAGRAPH = 2
%PROXIMITY_UNIT_CHAPTER   = 3

' // Size = 12 bytes
TYPE DBCONTENTPROXIMITY WORD
   dwProximityUnit     AS DWORD   ' DWORD // words, paras, chapters etc.
   ulProximityDistance AS DWORD   ' ULONG // how near is "near"?
   lWeight             AS LONG    ' LONG // weight of the proximity node
END TYPE

' // Size = 20 bytes
TYPE DBPROBABILISTIC WORD
   lWeight AS LONG     ' LONG
   flK1    AS SINGLE   ' float
   flK2    AS SINGLE   ' float
   flK3    AS SINGLE   ' float
   flB     AS SINGLE   ' float
END TYPE

' // Size = 20 bytes
TYPE DBRELEVANTDOCUMENT WORD
   lWeight   AS LONG         ' LONG
   vDocument AS tagVARIANT   ' VARIANT
END TYPE

'typedef struct tagDBCOMMANDTREE
'    {
'    DBCOMMANDOP op;
'    WORD wKind;
'    struct tagDBCOMMANDTREE *pctFirstChild;
'    struct tagDBCOMMANDTREE *pctNextSibling;
'    /* [switch_is][switch_type] */ union
'        {
'        /* [case()] */ __int64 llValue;
'        /* [case()] */ unsigned __int64 ullValue;
'        /* [case()] */ BOOL fValue;
'        /* [case()] */ unsigned char uchValue;
'        /* [case()] */ signed char schValue;
'        /* [case()] */ unsigned short usValue;
'        /* [case()] */ short sValue;
'        /* [case()] */ LPOLESTR pwszValue;
'        /* [case()] */ LONG lValue;
'        /* [case()] */ ULONG ulValue;
'        /* [case()] */ float flValue;
'        /* [case()] */ double dblValue;
'        /* [case()] */ CY cyValue;
'        /* [case()] */ DATE dateValue;
'        /* [case()] */ DBDATE dbdateValue;
'        /* [case()] */ DBTIME dbtimeValue;
'        /* [case()] */ SCODE scodeValue;
'        /* [case()] */ BSTR *pbstrValue;
'        /* [case()] */ ICommand *pCommand;
'        /* [case()] */ IDispatch *pDispatch;
'        /* [case()] */ IMoniker *pMoniker;
'        /* [case()] */ IRowset *pRowset;
'        /* [case()] */ IUnknown *pUnknown;
'        /* [case()] */ DBBYGUID *pdbbygdValue;
'        /* [case()] */ DBCOLUMNDESC *pcoldescValue;
'        /* [case()] */ DBID *pdbidValue;
'        /* [case()] */ DBLIKE *pdblikeValue;
'        /* [case()] */ DBCONTENT *pdbcntntValue;
'        /* [case()] */ DBCONTENTSCOPE *pdbcntntscpValue;
'        /* [case()] */ DBCONTENTTABLE *pdbcntnttblValue;
'        /* [case()] */ DBCONTENTVECTOR *pdbcntntvcValue;
'        /* [case()] */ DBCONTENTPROXIMITY *pdbcntntproxValue;
'        /* [case()] */ DBGROUPINFO *pdbgrpinfValue;
'        /* [case()] */ DBPARAMETER *pdbparamValue;
'        /* [case()] */ DBPROPSET *pdbpropValue;
'        /* [case()] */ DBSETFUNC *pdbstfncValue;
'        /* [case()] */ DBSORTINFO *pdbsrtinfValue;
'        /* [case()] */ DBTEXT *pdbtxtValue;
'        /* [case()] */ DBVECTOR *pdbvectorValue;
'        /* [case()] */ SAFEARRAY *parrayValue;
'        /* [case()] */ VARIANT *pvarValue;
'        /* [case()] */ GUID *pGuid;
'        /* [case()] */ BYTE *pbValue;
'        /* [case()] */ char *pzValue;
'        /* [case()] */ DB_NUMERIC *pdbnValue;
'        /* [case()] */ DBTIMESTAMP *pdbtsValue;
'        /* [case()] */ void *pvValue;
'        /* [case()] */ DBPROBABILISTIC *pdbprobValue;
'        /* [case()] */ DBRELEVANTDOCUMENT *pdbreldocValue;
'        }    value;
'    HRESULT hrError;
'    }    DBCOMMANDTREE;

UNION DBCOMMANDTREE_VALUE_UNION
   fValue            AS LONG                     ' BOOL // DBVALUEKIND_BOOL (DBTYPE_BOOL)
   uchValue          AS BYTE                     ' unsigned char // DBVALUEKIND_UI1 (DBTYPE_UI1)
   schValue          AS BYTE                     ' signed char // DBVALUEKIND_I1 (DBTYPE_I1)
   usValue           AS WORD                     ' unsigned short // DBVALUEKIND_UI2 (DBTYPE_UI2)
   sValue            AS INTEGER                  ' short // DBVALUEKIND_I2 (DBTYPE_I2)
   pwszValue         AS WSTRINGZ PTR             ' LPOLESTR // DBVALUEKIND_WSTR (DBTYPE_WSTR)
   lValue            AS LONG                     ' LONG // DBVALUEKIND_I4 (DBTYPE_I4)
   ulValue           AS DWORD                    ' ULONG // DBVALUEKIND_UI4 (DBTYPE_UI4)
   flValue           AS SINGLE                   ' float // DBVALUEKIND_R4 (DBTYPE_R4)
   dblValue          AS DOUBLE                   ' double // DBVALUEKIND_R8 (DBTYPE_R8)
   cyValue           AS CUR                      ' CY // DBVALUEKIND_CY (DBTYPE_CY)
   dateValue         AS DOUBLE                   ' DATE // DBVALUEKIND_DATE (DBTYPE_DATE)
   dbdateValue       AS DBDATE                   ' DBDATE // DBVALUEKIND_DBDATE (DBTYPE_DBDATE)
   dbtimeValue       AS DBTIME                   ' DBTIME // DBVALUEKIND_DBTIME (DBTYPE_DBTIME)
   scodeValue        AS LONG                     ' SCODE // DBVALUEKIND_ERROR (DBTYPE_ERROR)
   llValue           AS QUAD                     ' __int64 // DBVALUEKIND_I8 (DBTYPE_I8)
   ullValue          AS QUAD                     ' unsigned __int64 // DBVALUEKIND_UI8 (DBTYPE_UI8)
   pbstrValue        AS DWORD                    ' BSTR * // DBVALUEKIND_BSTR (DBTYPE_BSTR)
   pCommand          AS DWORD                    ' ICommand * // DBVALUEKIND_COMMAND (DBTYPE_IUNKNOWN)
   pDispatch         AS DWORD                    ' IDispatch * // DBVALUEKIND_IDISPATCH (DBTYPE_IDISPATCH)
   pMoniker          AS DWORD                    ' IMoniker * // DBVALUEKIND_MONIKER (DBTYPE_MONIKER)
   pRowset           AS DWORD                    ' IRowset * // DBVALUEKIND_ROWSET (DBTYPE_ROWSET)
   pUnknown          AS DWORD                    ' IUnknown * // DBVALUEKIND_IUNKNOWN (DBTYPE_IUNKNOWN)
   pdbbygdValue      AS DBBYGUID PTR             ' DBBYGUID * // DBVALUEKIND_BYGUID
   pcoldescValue     AS DBCOLUMNDESC PTR         ' DBCOLUMNDESC * // DBVALUEKIND_COLDESC
   pdbidValue        AS DBID PTR                 ' DBID * // DBVALUEKIND_ID
   pdblikeValue      AS DBLIKE PTR               ' DBLIKE * // DBVALUEKIND_LIKE
   pdbcntntValue     AS DBCONTENT PTR            ' DBCONTENT * // DBVALUEKIND_CONTENT
   pdbcntntvcValue   AS DBCONTENTVECTOR PTR      ' DBCONTENTVECTOR * // DBVALUEKIND_CONTENTVECTOR
   pdbcntntproxValue AS DBCONTENTPROXIMITY PTR   ' DBCONTENTPROXIMITY * // DBVALUEKIND_CONTENTPROXIMITY
   pdbgrpinfValue    AS DBGROUPINFO PTR          ' DBGROUPINFO * // DBVALUEKIND_GROUPINFO
   pdbparamValue     AS DBPARAMETER PTR          ' DBPARAMETER * // DBVALUEKIND_PARAMETER
   pdbpropValue      AS DBPROPSET PTR            ' DBPROPSET * // DBVALUEKIND_PROPERTY
   pdbstfncValue     AS DBSETFUNC PTR            ' DBSETFUNC * // DBVALUEKIND_SETFUNC
   pdbsrtinfValue    AS DBSORTINFO PTR           ' DBSORTINFO * // DBVALUEKIND_SORTINFO
   pdbtxtValue       AS DBTEXT PTR               ' DBTEXT * // DBVALUEKIND_TEXT
   pdbvectorValue    AS DBVECTOR PTR             ' DBVECTOR * // DBVALUEKIND_VECTOR | *
   parrayValue       AS DWORD                    ' SAFEARRAY * // DBVALUEKIND_ARRAY | *
   pvarValue         AS tagVARIANT PTR           ' VARIANT * // DBVALUEKIND_VARIANT (DBTYPE_VARIANT)
   pGuid             AS GUID PTR                 ' GUID * // DBVALUEKIND_GUID (DBTYPE_GUID)
   pbValue           AS BYTE PTR                 ' BYTE * // DBVALUEKIND_BYTES (DBTYPE_BYTES)
   pzValue           AS ASCIIZ PTR               ' CHAR * // DBVALUEKIND_STR (DBTYPE_STR)
   pdbnValue         AS DB_NUMERIC PTR           ' DB_NUMERIC * // DBVALUEKIND_NUMERIC (DBTYPE_NUMERIC)
   pdbtsValue        AS DBTIMESTAMP PTR          ' DBTIMESTAMP * // DBVALUEKIND_DBTIMESTAMP (DBTYPE_DBTIMESTAMP)
   pvValue           AS DWORD PTR                ' void * // a generic DBVALUEKIND_BYREF
END UNION

' // Size = 24 bytes
TYPE DBCOMMANDTREE WORD
   op               AS WORD                      ' // Operator identifier (2 bytes)
   wKind            AS WORD                      ' // Discriminator for the following union (2 bytes)
   pctFirstChild    AS DWORD                     ' // Pointer to first child (4 bytes)
   pctNextSibling   AS DWORD                     ' // Pointer to sibling (4 bytes)
   value            AS DBCOMMANDTREE_VALUE_UNION ' // Union directly represents fields that fit within 8 bytes.
   hrError          AS DWORD                     ' // Error indicator, details in Extended Error info (4 bytes)
END TYPE

$IID_ICommandTree = GUID$("{0C733A87-2A1C-11CE-ADE5-00AA0044773D}")

INTERFACE ICommandTree $IID_ICommandTree

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindErrorNodes ( _                            ' VTable offset = 12
     BYREF pRoot AS DBCOMMANDTREE _                     ' __in const DBCOMMANDTREE *pRoot
   , BYREF pcErrorNodes AS DWORD _                      ' __out ULONG *pcErrorNodes
   , BYREF prgErrorNodes AS DWORD _                     ' __out DBCOMMANDTREE ***prgErrorNodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeCommandTree ( _                           ' VTable offset = 16
     BYREF ppRoot AS DBCOMMANDTREE _                    ' __in DBCOMMANDTREE **ppRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCommandTree ( _                            ' VTable offset = 20
     BYREF ppRoot AS DBCOMMANDTREE _                    ' __out DBCOMMANDTREE **ppRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCommandTree ( _                            ' VTable offset = 24
     BYREF ppRoot AS DBCOMMANDTREE _                    ' __in DBCOMMANDTREE **ppRoot
   , BYVAL dwCommandReuse AS DWORD _                    ' __in DBCOMMANDREUSE dwCommandReuse
   , BYVAL fCopy AS LONG _                              ' __in BOOL fCopy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommandTree_INTERFACE_DEFINED__ */


' ########################################################################################
' IQuery interface
' IID = 0C733A51-2A1C-11CE-ADE5-00AA0044773D
' Inherited interface = ICommandTree
' ########################################################################################

#IF NOT %DEF(%IQuery_INTERFACE_DEFINED)
%IQuery_INTERFACE_DEFINED = 1

INTERFACE IQuery $IID_IQuery

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindErrorNodes ( _                            ' VTable offset = 12
     BYREF pRoot AS DBCOMMANDTREE _                     ' __in const DBCOMMANDTREE *pRoot
   , BYREF pcErrorNodes AS DWORD _                      ' __out ULONG *pcErrorNodes
   , BYREF prgErrorNodes AS DWORD _                     ' __out DBCOMMANDTREE ***prgErrorNodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeCommandTree ( _                           ' VTable offset = 16
     BYREF ppRoot AS DBCOMMANDTREE _                    ' __in DBCOMMANDTREE **ppRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCommandTree ( _                            ' VTable offset = 20
     BYREF ppRoot AS DBCOMMANDTREE _                    ' __out DBCOMMANDTREE **ppRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCommandTree ( _                            ' VTable offset = 24
     BYREF ppRoot AS DBCOMMANDTREE _                    ' __in DBCOMMANDTREE **ppRoot
   , BYVAL dwCommandReuse AS DWORD _                    ' __in DBCOMMANDREUSE dwCommandReuse
   , BYVAL fCopy AS LONG _                              ' __in BOOL fCopy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPostProcessing ( _                         ' VTable offset = 28
     BYREF ppRoot AS DBCOMMANDTREE _                    ' __in DBCOMMANDTREE **ppRoot
   , BYVAL fCopy AS LONG _                              ' __in BOOL fCopy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCardinalityEstimate ( _                    ' VTable offset = 32
     BYREF pulCardinality AS DWORD _                    ' __out DBORDINAL *pulCardinality
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQuery_INTERFACE_DEFINED__ */

'#include <poppack.h>     // restore original structure packing
