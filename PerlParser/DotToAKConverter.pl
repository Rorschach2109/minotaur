#!/usr/bin/perl

#*
#* This file is part of minotaur.
#*
#* File: DotToAKConverter.pl
#* Brief: Perl script that converts Dot format file to AK file.
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

	my $nodesNumber = 0;
	my $edgesNumber = 0;

	sub WriteGraphNumber
	{
		print AK_GRAPH_FILE "1\n\n";
	}

	sub WriteGraphName
	{
		while ( <DOT_GRAPH_FILE> )
		{
			chomp;
			if ( $_ =~ /graph\s+(\w+)\s*/ )
			{
				print AK_GRAPH_FILE $1."\n\n";
			}
			if ( $_ =~ /{/ )
			{
				return;
			}
		}
	}

	sub IgnoreStyles
	{
		while ( <DOT_GRAPH_FILE> )
		{
			chomp;
			if ( /^\s*$/ )
			{
				return;
			}
		}
	}

	sub WriteNodes
	{
		while ( <DOT_GRAPH_FILE> )
		{
			chomp;
			if ( $_ =~ /\s+([0-9]+).+" *([0-9]+), *([0-9]+).+/ )
			{
				print AK_GRAPH_FILE "$1\t$2\t$3\n";
				$nodesNumber++;
			}
			if ( /^\s*$/ )
			{
				print AK_GRAPH_FILE "\n";
				return;
			}
		}
	}


	sub WriteEdges
	{
		while ( <DOT_GRAPH_FILE> )
		{
			chomp;
			if ( $_ =~ /\s+([0-9]+)\s*--\s*([0-9]+).+" *([0-9]+\.[0-9]) *".+\s*/ )
			{
				print AK_GRAPH_FILE "$1\t$2\t$3\n";
				$edgesNumber++;
			}
			if ( /^\s*$/ )
			{
				print AK_GRAPH_FILE "\n";
				return;
			}
		}
	}

	sub AppendLine
	{
		open AK_GRAPH_FILE, "<$akFilePath";
		my @lines = <AK_GRAPH_FILE>;
		
		my @newLines;
		$newLines[0] = shift(@lines);
		$newLines[1] = shift(@lines);
		$newLines[2] = shift(@lines);
		$newLines[3] = "\n";
		$newLines[4] = $nodesNumber . "\t" . $edgesNumber . "\n";

		push @newLines, @lines;

		close AK_GRAPH_FILE;

		return @newLines;
	}

	if( open DOT_GRAPH_FILE, "<$dotFilePath" )
	{
		open AK_GRAPH_FILE, ">$akFilePath";

		WriteGraphNumber;
		WriteGraphName;
		IgnoreStyles;
		WriteNodes;
		WriteEdges;

		close AK_GRAPH_FILE;
		close DOT_GRAPH_FILE;

		my @linesToWrite = AppendLine;

		open AK_GRAPH_FILE, ">$akFilePath";

		foreach my $line (@linesToWrite)
		{
			print AK_GRAPH_FILE "$line";
		}

		close AK_GRAPH_FILE;
	}
	else
	{
		die "Cannot open file: $dotFilePath\n$!\n";
	}
}
else
{
	print "No Argument Delivered!\n";
}
