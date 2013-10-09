#!/usr/bin/perl

#*
#* This file is part of minotaur.
#*
#* File: AKToDotConverter.pl
#* Brief: Perl script that converts AK format file to Dot file.
#*
#* Date: 08.10.2013
#* Author: Andrzej Korycinski
#* 
#*

use strict;
use warnings;

if ( defined( my $graphName = $ARGV[0] ) )
{
	my $akFilePath = "./GraphFiles/AKGraphs/" . $graphName;
	my $dotFilePath = "./GraphFiles/DotGraphs/" . $graphName . ".dot";

	sub IgnoreTillEmptyLine
	{
		while ( <AK_GRAPH_FILE> )
		{
			if ( /^\s*$/ )
			{
				return;
			}
		}
	}

	sub WriteGraphName
	{
		IgnoreTillEmptyLine;
		chomp ( $graphName = <AK_GRAPH_FILE> );
		print DOT_GRAPH_FILE "graph $graphName\n{\n";
		<AK_GRAPH_FILE>;
	}

	sub WriteStyles
	{
		print DOT_GRAPH_FILE "\tgraph[center = true, margin = 0.2, nodesep = 0.1, ranksep = 0.3]\n";
		print DOT_GRAPH_FILE "\tnode[shape = circle, fontsize = 8];\n";
		print DOT_GRAPH_FILE "\tedge[arrowsize = 0.6, fontsize = 8];\n";
		print DOT_GRAPH_FILE "\n";
	}

	sub WriteNodes
	{
		while ( <AK_GRAPH_FILE> )
		{
			chomp;
			if ( $_ =~ /([0-9]+)\s+([0-9]+)\s+([0-9]+)\s*/ )
			{
				print DOT_GRAPH_FILE "\t$1 [pos = \"$2, $3\"];\n";
			}
			if ( /^\s*$/ )
			{
				print DOT_GRAPH_FILE "\n";
				return;
			}
		}
	}

	sub WriteEdges
	{
		while ( <AK_GRAPH_FILE> )
		{
			chomp;
			if ( $_ =~ /([0-9]+)\s+([0-9]+)\s+([0-9]+\.[0-9])\s*/ )
			{
				print DOT_GRAPH_FILE "\t$1 -- $2 [label = \"$3\"];\n";
			}
			if ( /^\s*$/ )
			{
				return;
			}
		}
	}

	sub WriteEnding
	{
		print DOT_GRAPH_FILE "}\n\n";
	}

	if( open AK_GRAPH_FILE, "<$akFilePath" )
	{
		open DOT_GRAPH_FILE, ">$dotFilePath";

		WriteGraphName;
		WriteStyles;
		IgnoreTillEmptyLine;
		WriteNodes;
		WriteEdges;
		WriteEnding;

		close DOT_GRAPH_FILE;
		close AK_GRAPH_FILE;
	}
	else
	{
		die "Cannot open file: $akFilePath\n$!\n";
	}
}
else
{
	print "No Argument Delivered!\n";
}
